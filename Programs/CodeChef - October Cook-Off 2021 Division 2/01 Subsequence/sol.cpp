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
        if (n == 1)
        {
            lll temp;
            cin >> temp;
            cout << temp << "\n"
                 << 0 << "\n";
            continue;
        }

        vector<lll> odd, even;
        for (lll i = 0; i < n; i++)
        {
            lll temp;
            cin >> temp;
            if (i % 2 == 0)
            {
                even.emplace_back(temp);
            }
            else
            {
                odd.emplace_back(temp);
            }
        }
        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end());
        for (lll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cout << even[i / 2] << " ";
            }
            else
            {
                cout << odd[i / 2] << " ";
            }
        }
        cout << "\n";
        lll ans = 0;
        lll cumulative[odd.size()] = {0};
        cumulative[odd.size() - 1] = odd[odd.size() - 1];
        for (lll i = odd.size() - 2; i >= 0; i--)
        {
            cumulative[i] = cumulative[i + 1] + odd[i];
        }
        for (lll i = 0; i < (lll)even.size() && i < (lll)odd.size(); i++)
        {
            ans += even[i] * cumulative[i];
        }
        cout << ans << "\n";
    }
}