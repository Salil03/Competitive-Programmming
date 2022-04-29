#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

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
        vector<vector<bool>> a(n, vector<bool>(n, 0)), b(n, vector<bool>(n, 0));
        for (lll i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (lll j = 0; j < n; j++)
            {
                if (s[j] == '0')
                {
                    a[i][j] = 0;
                }
                else
                {
                    a[i][j] = 1;
                }
            }
        }
        for (lll i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (lll j = 0; j < n; j++)
            {
                if (s[j] == '0')
                {
                    b[i][j] = 0;
                }
                else
                {
                    b[i][j] = 1;
                }
            }
        }
        for (lll i = 0; i < n; i++)
        {
            if (a[i][0] != b[i][0])
            {
                for (lll j = 0; j < n; j++)
                {
                    a[i][j] = !a[i][j];
                }
            }
        }
        for (lll i = 0; i < n; i++)
        {
            if (a[0][i] != b[0][i])
            {
                for (lll j = 0; j < n; j++)
                {
                    a[j][i] = !a[j][i];
                }
            }
        }
        bool flag = true;
        for (lll i = 0; i < n; i++)
        {
            for (lll j = 0; j < n; j++)
            {
                if (a[i][j] != b[i][j])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}