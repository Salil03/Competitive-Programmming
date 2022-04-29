#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution < lll>(low, high)(rng)
// uniform_real_distribution<double>(low, high)(rng)

typedef tree<lll, null_type, less<lll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<lll, lll>, null_type, less<pair<lll, lll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// gp_hash_table<int, int> table; unordered map

#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

void build_tree(vector<lll> &b, vector<lll> &seg_tree,
                lll l, lll r, lll vertex)
{
    // Termination Condition
    if (l == r)
    {
        seg_tree[vertex] = b[l];
        return;
    }

    // Find the mid value
    lll mid = (l + r) / 2;

    // Left and Right Recursive Call
    build_tree(b, seg_tree, l, mid,
               2 * vertex);
    build_tree(b, seg_tree, mid + 1,
               r, 2 * vertex + 1);

    // Update the Segment Tree Node
    seg_tree[vertex] = __gcd(seg_tree[2 * vertex],
                             seg_tree[2 * vertex + 1]);
}

// Function to return the GCD of the
// elements of the Array from index
// l to index r
lll range_gcd(vector<lll> &seg_tree, lll v,
              lll tl, lll tr,
              lll l, lll r)
{
    // Base Case
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return seg_tree[v];

    // Find the middle range
    lll tm = (tl + tr) / 2;

    // Find the GCD and return
    return __gcd(
        range_gcd(seg_tree, 2 * v, tl,
                  tm, l, min(tm, r)),

        range_gcd(seg_tree, 2 * v + 1,
                  tm + 1, tr,
                  max(tm + 1, l), r));
}

// Function to prlll maximum length of
// the subarray having GCD > one
lll maxSubarrayLen(vector<lll> &arr, lll n)
{
    // Stores the Segment Tree
    vector<lll> seg_tree(4 * (n) + 1, 0);

    // Function call to build the
    // Segment tree from array arr[]
    build_tree(arr, seg_tree, 0, n - 1, 1);

    // Store maximum length of subarray
    lll maxLen = 0;

    // Starting and ending polller of
    // the current window
    lll l = 0, r = 0;

    while (r < n && l < n)
    {

        // Case where the GCD of the
        // current window is 1
        if (range_gcd(seg_tree, 1, 0,
                      n - 1, l, r) == 1)
        {
            l++;
        }

        // Update the maximum length
        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    // Print answer
    return maxLen;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll t;
    cin >> t;
    while (t--)
    {
        lll n;
        cin >> n;
        vector<lll> arr(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        vector<lll> diff(n - 1);
        for (lll i = 0; i < n - 1; i++)
        {
            diff[i] = abs(arr[i + 1] - arr[i]);
        }
        cout << maxSubarrayLen(diff, n - 1) + 1 << "\n";
    }
}