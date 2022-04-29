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
        vector<lll> ans(n, -1);
        vector<pair<lll, lll>> robo(n);
        vector<char> direction(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> robo[i].first;
            robo[i].second = i;
        }
        for (lll i = 0; i < n; i++)
        {
            cin >> direction[i];
        }
        sort(robo.begin(), robo.end());
        stack<pair<lll, lll>> even, odd;
        for (lll i = 0; i < n; i++)
        {
            if (robo[i].first & 1)
            {
                if (direction[robo[i].second] == 'R')
                {
                    odd.push(robo[i]);
                }
                else if (odd.empty())
                {
                    odd.push(make_pair(-robo[i].first, robo[i].second));
                }
                else
                {
                    pair<lll, lll> robo_crash = odd.top();
                    ans[robo[i].second] = abs(robo[i].first - robo_crash.first) / 2;
                    ans[robo_crash.second] = abs(robo[i].first - robo_crash.first) / 2;
                    odd.pop();
                }
            }
            else
            {
                if (direction[robo[i].second] == 'R')
                {
                    even.push(robo[i]);
                }
                else if (even.empty())
                {
                    even.push(make_pair(-robo[i].first, robo[i].second));
                }
                else
                {
                    pair<lll, lll> robo_crash = even.top();
                    ans[robo[i].second] = abs(robo[i].first - robo_crash.first) / 2;
                    ans[robo_crash.second] = abs(robo[i].first - robo_crash.first) / 2;
                    even.pop();
                }
            }
        }
        while (odd.size() > 1)
        {
            pair<lll, lll> fir = odd.top();
            odd.pop();
            pair<lll, lll> sec = odd.top();
            odd.pop();
            ans[fir.second] = abs(2 * m - fir.first - sec.first) / 2;
            ans[sec.second] = abs(2 * m - fir.first - sec.first) / 2;
        }
        while (even.size() > 1)
        {
            pair<lll, lll> fir = even.top();
            even.pop();
            pair<lll, lll> sec = even.top();
            even.pop();
            ans[fir.second] = abs(2 * m - fir.first - sec.first) / 2;
            ans[sec.second] = abs(2 * m - fir.first - sec.first) / 2;
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}
