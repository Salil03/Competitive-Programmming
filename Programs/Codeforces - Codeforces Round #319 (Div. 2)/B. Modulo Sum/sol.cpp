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
    lll n, m;
    cin >> n >> m;
    vector<lll> arr(n);
    vector<bool> modulo(m, 0);
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (arr[0] % m == 0)
    {
        cout << "YES";
        return 0;
    }
    modulo[arr[0] % m] = true;
    for (lll i = 1; i < n; i++)
    {
        if (arr[i] % m == 0)
        {
            cout << "YES";
            return 0;
        }
        if (modulo[m - (arr[i] % m)])
        {
            cout << "YES";
            return 0;
        }
        stack<lll> update;
        for (lll j = 0; j < m; j++)
        {
            if (modulo[j] && !modulo[(j + arr[i]) % m])
            {
                update.push((j + arr[i]) % m);
            }
        }
        while (!update.empty())
        {
            modulo[update.top()] = true;
            update.pop();
        }
        modulo[arr[i] % m] = true;
    }
    cout << "NO";
}