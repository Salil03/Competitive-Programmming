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
        lll n, q;
        cin >> n >> q;
        bool arr[n][26];
        memset(arr, 0, sizeof(arr));
        string s;
        cin >> s;
        for (auto c : s)
        {
            arr[0][c - 'a'] = 1;
        }
        for (lll i = 1; i < n; i++)
        {
            cin >> s;
            for (lll j = 0; j < 26; j++)
            {
                arr[i][j] = arr[i - 1][j];
            }
            for (auto c : s)
            {
                arr[i][c - 'a'] = !arr[i - 1][c - 'a'];
            }
        }
        while (q--)
        {
            lll m;
            char c;
            cin >> m >> c;
            if (arr[m - 1][c - 'a'])
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
    }
}