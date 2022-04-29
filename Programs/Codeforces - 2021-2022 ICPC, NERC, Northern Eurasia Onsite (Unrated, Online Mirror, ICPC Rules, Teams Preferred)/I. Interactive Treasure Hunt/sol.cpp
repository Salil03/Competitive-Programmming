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
        lll n, m;
        cin >> n >> m;
        cout << "SCAN 1 1" << endl;
        lll a;
        cin >> a;
        cout << "SCAN 1 " << m << endl;
        lll b;
        cin >> b;
        lll sumx = (a + b + 6 - 2 * m) / 2, sumy = (a - b + 2 + 2 * m) / 2;
        cout << "SCAN " << sumx / 2 << " 1" << endl;
        lll c;
        cin >> c;
        cout << "SCAN 1 " << sumy / 2 << endl;
        lll d;
        cin >> d;
        lll diffx = c - sumy + 2;
        lll diffy = d - sumx + 2;
        cout << "DIG " << (sumx - diffx) / 2 << " " << (sumy - diffy) / 2 << endl;
        bool flag;
        cin >> flag;
        if (flag)
        {
            cout << "DIG " << (sumx + diffx) / 2 << " " << (sumy + diffy) / 2 << endl;
            cin >> flag;
        }
        else
        {
            cout << "DIG " << (sumx - diffx) / 2 << " " << (sumy + diffy) / 2 << endl;
            cin >> flag;
            cout << "DIG " << (sumx + diffx) / 2 << " " << (sumy - diffy) / 2 << endl;
            cin >> flag;
        }
    }
}