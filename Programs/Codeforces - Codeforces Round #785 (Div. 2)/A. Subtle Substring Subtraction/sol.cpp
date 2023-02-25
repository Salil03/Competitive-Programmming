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
        string s;
        cin >> s;
        lll n = s.length();
        lll sum = 0;
        if (n % 2 == 0)
        {
            for (lll i = 0; i < n; i++)
            {
                sum += (s[i] - 'a') + 1;
            }
            cout << "Alice " << sum << "\n";
        }
        else
        {
            if (n == 1)
            {
                cout << "Bob " << (s[0] - 'a') + 1 << "\n";
            }
            else
            {
                lll curr1 = 0;
                for (lll i = 1; i < n; i++)
                {
                    curr1 += (s[i] - 'a') + 1;
                }
                lll curr2 = 0;
                for (lll i = 0; i < n - 1; i++)
                {
                    curr2 += (s[i] - 'a') + 1;
                }
                // dbg(curr1);
                // dbg(curr2);
                if (curr1 >= curr2)
                {
                    cout << "Alice " << curr1 - (s[0] - 'a') - 1 << "\n";
                }
                else
                {
                    cout << "Alice " << curr2 - (s[n - 1] - 'a') - 1 << "\n";
                }
            }
        }
    }
}