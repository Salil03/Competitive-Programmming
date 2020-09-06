// OPTIMIZATIONS
//#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// OPTIMIZATIONS
#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define _GLIBCXX_DEBUG
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
const ll N = 1e5;
ll lazy[4 * N];
ll tree[4 * N];
ll arr[N];

void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        tree[node] = arr[l];
    }
    else
    {
        ll mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}
// l - r node range
// st - en update range
void update(ll node, ll l, ll r, ll st, ll en, ll val)
{
    if (lazy[node] != 0)
    {
        tree[node] += (r - l + 1) * lazy[node];
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }
    if (l > en || r < st)
        return;
    if (l >= st && en <= r)
    {
        tree[node] += (r - l + 1) * val;
        lazy[node * 2] += val;
        lazy[node * 2 + 1] = val;
        return;
    }
    ll mid = (l + r) / 2;
    update(node * 2, l, mid, st, en, val);
    update(node * 2 + 1, mid + 1, r, st, en, val);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
// l - r node range
// st - en query range
ll query(ll node, ll l, ll r, ll st, ll en)
{
    if (l > en || r < st)
        return 0;
    if (lazy[node] != 0)
    {
        tree[node] += (r - l + 1) * lazy[node];
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }
    if (l >= st && en <= r)
    {
        return tree[node];
    }
    ll mid = (l + r) / 2;
    ll p1 = query(node * 2, l, mid, st, en);
    ll p2 = query(node * 2 + 1, mid + 1, r, st, en);
    return max(p1, p2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
}