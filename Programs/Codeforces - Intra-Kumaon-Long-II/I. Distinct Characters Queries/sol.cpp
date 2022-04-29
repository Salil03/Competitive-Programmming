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
    string s;
    cin >> s;
    lll len = s.length();
    vector<multiset<lll>> segment(26);
    for (lll i = 0; i < len; i++)
    {
        segment[s[i] - 'a'].insert(i);
    }
    lll q;
    cin >> q;
    while (q--)
    {
        lll query;
        cin >> query;
        if (query == 1)
        {
            lll pos;
            char c;
            cin >> pos >> c;
            lll char_to_num = s[pos - 1] - 'a';
            segment[char_to_num].erase(pos - 1);
            s[pos - 1] = c;
            char_to_num = s[pos - 1] - 'a';
            segment[char_to_num].insert(pos - 1);
        }
        else
        {
            lll l, r, ans = 0;
            cin >> l >> r;
            for (lll i = 0; i < 26; i++)
            {
                ans += segment[i].lower_bound(l - 1) != segment[i].end() && *segment[i].lower_bound(l - 1) < r;
            }
            cout << ans << "\n";
        }
    }
}