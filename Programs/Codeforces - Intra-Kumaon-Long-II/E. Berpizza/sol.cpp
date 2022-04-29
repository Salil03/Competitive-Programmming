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
    lll q;
    cin >> q;
    set<pair<lll, lll>> mono, poly;
    lll curr = 1;
    while (q--)
    {
        lll x;
        cin >> x;
        if (x == 1)
        {
            lll m;
            cin >> m;
            mono.insert(make_pair(curr, m));
            poly.insert(make_pair(-m, curr));
            curr++;
        }
        if (x == 2)
        {
            pair<lll, lll> cust = *mono.begin();
            cout << cust.first << " ";
            poly.erase(make_pair(-cust.second, cust.first));
            mono.erase(cust);
        }
        if (x == 3)
        {
            pair<lll, lll> cust = *poly.begin();
            cout << cust.second << " ";
            mono.erase(make_pair(cust.second, -cust.first));
            poly.erase(cust);
        }
    }
}