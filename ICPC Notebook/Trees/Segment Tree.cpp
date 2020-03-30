#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n;
int tree[4 * MAXN] = {};
int arr[MAXN] = {};
void build(int node, int left, int right)
{
    if (left == right)
    {
        tree[node] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2 * node, left, mid);
    build(2 * node + 1, mid + 1, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int node, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        tree[node] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(node * 2, tl, tm, pos, new_val);
        }
        else
        {
            update(node * 2 + 1, tm + 1, tr, pos, new_val);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
void range_update(int node, int tl, int tr, int l, int r, int add)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        tree[node] += add;
    }
    else
    {
        int tm = (tl + tr) / 2;
        range_update(node * 2, tl, tm, l, min(r, tm), add);
        range_update(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    range_update(1, 0, n - 1, 2, 4, 86);
    cout << query(1, 0, n - 1, 1, 4);
}