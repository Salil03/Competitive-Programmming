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
    lll n;
    cin >> n;
    lll left = n;
    multiset<pair<lll, lll>> s;
    vector<lll> arr(n);
    bool del[n];
    memset(del, 0, sizeof(del));
    for (lll i = 0; i < n; i++)
    {
        lll x;
        cin >> x;
        s.insert(make_pair(x, i));
        arr[i] = x;
    }
    while (!s.empty())
    {
        // dbg(s);
        pair<lll, lll> fir = *s.begin();
        s.erase(fir);
        if (s.empty())
        {
            break;
        }
        pair<lll, lll> sec = *s.begin();
        if (fir.first == sec.first)
        {
            del[fir.second] = true;
            left--;
            s.erase(sec);
            arr[sec.second] *= 2;
            s.insert(make_pair(sec.first * 2, sec.second));
        }
    }
    cout << left << "\n";
    for (lll i = 0; i < n; i++)
    {
        if (!del[i])
        {
            cout << arr[i] << " ";
        }
    }
}