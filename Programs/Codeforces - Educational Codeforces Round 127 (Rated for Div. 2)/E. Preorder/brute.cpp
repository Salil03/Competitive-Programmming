#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;
const int MN = 302144;
char tree[MN];
int index[MN];
int raito[MN];
char stree[MN];
int N;
int NN;
typedef unsigned long long ull;
const ull P = 9001;
const ull M = 1e9 + 7;
ull hashes[MN];
ull hashes2[MN];

ull PS[MN];
ull PS2[MN];

ull hashit(int a, int b)
{
    if (a == 0)
        return hashes[b];
    return hashes[b] - hashes[a - 1] * PS[b - a + 1];
}
ull hashit2(int a, int b)
{
    if (a == 0)
        return hashes2[b];
    return (hashes2[b] - ((hashes2[a - 1] * PS2[b - a + 1]) % M) + M) % M;
}
int memos[MN];
int st[MN];

bool hasToSwap;
struct tp
{
    char v;
    ull hs;
    tp *l, *r;
    int sz;
    string str;

    tp()
    {
        l = r = NULL;
        sz = 1;
        hs = 0;
        str = "";
    }
};

ull gh(tp *t)
{
    if (!t)
        return 0;
    return t->hs;
}
ull sz(tp *t)
{
    if (!t)
        return 0;
    return t->sz;
}
void update(tp *des)
{
    if (des == NULL)
    {
        return;
    }
    des->hs = gh(des->l) * PS[1 + sz(des->r)] + ((ull)des->v) * PS[sz(des->r)] + gh(des->r);
    des->sz = sz(des->l) + sz(des->r) + 1;
    des->str = des->v;
    if (des->l)
    {
        des->str = des->l->str + des->str + des->r->str;
    }
}
tp treapar[MN];
int ntt;
tp *ntp(char c)
{
    tp *res = &treapar[ntt++];
    res->l = res->r = NULL;
    res->v = c;
    return res;
}

int cmp(tp *a, tp *b)
{
    if (!a)
        return 0;
    for (int i = 0; i < a->str.size(); i++)
    {
        if (a->str[i] != b->str[i])
            return a->str[i] - b->str[i];
    }
    return 0;
}
tp *sortTree(int pos)
{
    if (pos > NN)
        return NULL;
    tp *c = ntp(tree[pos]);
    tp *a = sortTree(2 * pos);
    tp *b = sortTree(2 * pos + 1);
    c->l = a;
    c->r = b;
    update(c);
    if (cmp(a, b) < 0)
    {
        swap(c->l, c->r);
    }
    update(c);

    return c;
}

void preorden(int pos, int &tm)
{
    if (pos > NN)
        return;
    ++tm;
    index[pos] = tm;
    tree[tm] = stree[pos];

    preorden(2 * pos, tm);
    preorden(2 * pos + 1, tm);
    raito[pos] = tm;
}

const long long MOD = 998244353;

int memo[MN];

long long dp(int pos)
{
    if (2 * pos > NN)
    {
        return memo[pos] = 1;
    }
    bool f = true;
    for (int i = index[2 * pos], b = index[2 * pos + 1]; i <= raito[2 * pos]; i++, b++)
    {
        if (tree[i] != tree[b])
            f = false;
    }
    if (f == false)
    {
        //            cout << pos<<"?"<<endl;
        return memo[pos] = (2 * dp(2 * pos) * dp(2 * pos + 1)) % MOD;
    }
    return memo[pos] = (dp(2 * pos) * dp(2 * pos + 1)) % MOD;
}
// void transverse(int pos, int level, char * t) {
//
//     if (pos >NN)return;
//     transverse(2*pos, level+1,t);
//     for (int i=0; i <level; i++)cout <<"  ";
//     cout << t[pos]<<"\n";
//     transverse(2*pos+1, level+1,t);
// }
int rec(int p)
{
    if (p > NN)
        return 0;
    st[p] = 1;
    st[p] += rec(2 * p);
    st[p] += rec(2 * p + 1);
    return st[p];
}
void trr(int pos, tp *cur)
{
    if (!cur)
        return;
    stree[pos] = cur->v;
    trr(pos * 2, cur->l);
    trr(pos * 2 + 1, cur->r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> N;
    NN = (1 << N) - 1;
    PS[0] = 1;
    PS2[0] = 1;
    for (int i = 1; i < MN; i++)
    {
        PS[i] = PS[i - 1] * P;
        PS2[i] = (PS2[i - 1] * P) % M;
    }

    for (int i = 1; i < (1 << N); i++)
    {
        cin >> tree[i];
    }
    tp *x = sortTree(1);
    trr(1, x);
    for (int i = 1; i <= NN; i++)
    {
        stree[index[i]] = tree[i];
    }
    //    transverse(1, 0, tree);
    //    cout << endl;
    //    transverse(1, 0, stree);
    int TM = -1;
    preorden(1, TM);
    ull H = 0;
    ull H2 = 0;
    for (int i = 0; i < NN; i++)
    {
        H *= P;
        H2 *= P;
        H += 2 * (int(tree[i])) + 1;
        H2 += 2 * (int(tree[i])) + 1;
        H2 %= M;
        hashes[i] = H;
        hashes2[i] = H2;
    }
    cout << dp(1);
    //    cout << endl;
    //    for (int i=1; i<=NN; i++) {
    //        cout << stree[i]<<" ";
    //    }
    //
    //        cout << endl;
    //    cout << stree[5]<<" "<<stree[10]<<" "<<stree[11]<<endl;
    //    cout << index[10]<<" "<<raito[10]<<endl;
    //    cout << index[11]<<" "<<raito[11]<<endl;
    //    cout << hashit(index[10], raito[10])<<endl;
    //    cout << hashit(index[11], raito[11])<<endl;
    //    for (int i=1; i<=NN; i++) {
    //        cout << memo[i]<<" ";
    //    }
    return 0;
}
