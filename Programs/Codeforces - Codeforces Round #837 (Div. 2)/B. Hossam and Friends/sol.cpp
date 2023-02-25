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

bool binsearch(vector<lll> arr, lll low, lll high)
{
    if (low > high)
    {
        return false;
    }
    lll l = 0, r = arr.size();
    while (l < r)
    {
        lll mid = (l + r) / 2;
        if (arr[mid] > high)
        {
            r = mid;
        }
        else if (arr[mid] < low)
        {
            l = mid;
        }
        else
        {
            return true;
        }
    }
    return false;
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
        lll n, m;
        cin >> n >> m;
        vector<lll> graph[n + 1];
        for (lll i = 0; i < m; i++)
        {
            lll x, y;
            cin >> x >> y;
            graph[x].emplace_back(y);
            graph[y].emplace_back(x);
        }
        for (lll i = 0; i < n; i++)
        {
            sort(graph[i].begin(), graph[i].end());
        }
        lll cnt = 0, i = 1, j = 1;
        while (i <= n && j <= n)
        {
            if (binsearch(graph[j], i, j - 1))
            {
                i++;
            }
            else
            {
                lll len = j - i + 1;
                cnt += (len * (len + 1)) / 2 - (len * (len - 1)) / 2;
                j++;
            }
        }
        cout << cnt << "\n";
    }
}