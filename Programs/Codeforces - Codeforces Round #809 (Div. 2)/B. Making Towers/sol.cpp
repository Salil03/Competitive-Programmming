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
    lll t;
    cin >> t;
    while (t--)
    {
        lll n;
        cin >> n;
        vector<lll> arr[n];
        for (lll i = 0; i < n; i++)
        {
            lll temp;
            cin >> temp;
            temp--;
            arr[temp].emplace_back(i);
        }
        for (lll i = 0; i < n; i++)
        {
            lll cnt = 0;
            lll j = 0;
            lll length = arr[i].size();
            while (j < length)
            {
                cnt++;
                bool flag = false;
                for (lll k = j + 1; k < length; k++)
                {
                    if ((arr[i][k] - arr[i][j]) % 2 == 1)
                    {
                        j = k;
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
            cout << cnt << " ";
        }
        cout << "\n";
    }
}