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

bitset<4000005> Primes;
void SieveOfEratosthenes(int n)
{
    Primes[0] = 1;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (Primes[i / 2] == 0)
        {
            for (int j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}
vector<lll> prima;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    SieveOfEratosthenes(4000002);
    for (int i = 1; i <= 4000002; i++)
    {
        if (i == 2)
            prima.push_back(i);
        else if (i % 2 == 1 && Primes[i / 2] == 0)
            prima.push_back(i);
    }
    lll n = 100000;
    lll idx = 0;
    vector<lll> ans;
    while (n--)
    {
        cout << idx << "\n";
        while (idx < prima.size())
        {
            bool flag = true;
            for (auto i : ans)
            {
                if (i == 2)
                {
                    continue;
                }
                if (Primes[(prima[idx] + i + 1) / 2] == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans.push_back(prima[idx]);
                idx++;
                break;
            }
            else
            {
                idx++;
            }
        }
        if (idx == prima.size())
        {
            cout << "oops";
            return 0;
        }
    }
}