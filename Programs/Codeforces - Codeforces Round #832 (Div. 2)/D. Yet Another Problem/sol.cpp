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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, q;
    cin >> n >> q;
    vector<lll> arr(n);
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<lll> prefix(n);
    vector<lll> prefix_sum(n);
    map<lll, vector<lll>> xor_map_odd;
    map<lll, vector<lll>> xor_map_even;
    prefix[0] = arr[0];
    prefix_sum[0] = arr[0];
    xor_map_even[prefix[0]].push_back(0);
    for (lll i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] ^ arr[i];
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        if (i & 1)
        {
            xor_map_odd[prefix[i]].push_back(i);
        }
        else
        {
            xor_map_even[prefix[i]].push_back(i);
        }
    }
    while (q--)
    {
        lll l, r;
        cin >> l >> r;
        l--;
        r--;
        if ((l == 0 && prefix_sum[r] == 0) || (l != 0 && prefix_sum[r] - prefix_sum[l - 1] == 0))
        {
            cout << 0 << "\n";
        }
        else if ((l - r + 1) & 1)
        {
            if ((l == 0 && prefix[r] == 0) || (l != 0 && (prefix[r] ^ prefix[l - 1]) == 0))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else
        {
            if ((l == 0 && prefix[r] != 0) || (l != 0 && (prefix[r] ^ prefix[l - 1]) != 0))
            {
                cout << -1 << "\n";
            }
            else if (l == 0)
            {
                if (arr[r] == 0)
                {
                    cout << 1 << "\n";
                }
                else if (!xor_map_even[0].empty() && xor_map_even[0][0] <= r)
                {
                    cout << 2 << "\n";
                }
                else
                {
                    cout << -1 << "\n";
                }
            }
            else if (l != 0)
            {
                if (arr[l] == 0 || arr[r] == 0)
                {
                    cout << 1 << "\n";
                }
                else if (l & 1)
                {
                    if (!xor_map_odd[prefix[l - 1]].empty() && xor_map_odd[prefix[l - 1]][0] <= r && xor_map_odd[prefix[l - 1]].back() >= l && lower_bound(xor_map_odd[prefix[l - 1]].begin(), xor_map_odd[prefix[l - 1]].end(), l) < upper_bound(xor_map_odd[prefix[l - 1]].begin(), xor_map_odd[prefix[l - 1]].end(), r))
                    {
                        cout << 2 << "\n";
                    }
                    else
                    {
                        cout << -1 << "\n";
                    }
                }
                else
                {
                    if (!xor_map_even[prefix[l - 1]].empty() && xor_map_even[prefix[l - 1]][0] <= r && xor_map_even[prefix[l - 1]].back() >= l && lower_bound(xor_map_even[prefix[l - 1]].begin(), xor_map_even[prefix[l - 1]].end(), l) < upper_bound(xor_map_even[prefix[l - 1]].begin(), xor_map_even[prefix[l - 1]].end(), r))
                    {
                        cout << 2 << "\n";
                    }
                    else
                    {
                        cout << -1 << "\n";
                    }
                }
            }
        }
    }
}