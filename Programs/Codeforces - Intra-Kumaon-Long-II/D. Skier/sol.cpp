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
        string s;
        cin >> s;
        set<tuple<lll, lll, lll, lll>> sus;
        pair<lll, lll> curr = make_pair(0, 0);
        lll time = 0;
        for (auto i : s)
        {
            if (i == 'N')
            {
                if (sus.find(make_tuple(curr.first, curr.second, curr.first, curr.second + 1)) != sus.end() || sus.find(make_tuple(curr.first, curr.second + 1, curr.first, curr.second)) != sus.end())
                {
                    time += 1;
                }
                else
                {
                    time += 5;
                    sus.insert(make_tuple(curr.first, curr.second, curr.first, curr.second + 1));
                }
                curr = make_pair(curr.first, curr.second + 1);
            }
            else if (i == 'S')
            {
                if (sus.find(make_tuple(curr.first, curr.second, curr.first, curr.second - 1)) != sus.end() || sus.find(make_tuple(curr.first, curr.second - 1, curr.first, curr.second)) != sus.end())
                {
                    time += 1;
                }
                else
                {
                    time += 5;
                    sus.insert(make_tuple(curr.first, curr.second, curr.first, curr.second - 1));
                }
                curr = make_pair(curr.first, curr.second - 1);
            }
            else if (i == 'E')
            {
                if (sus.find(make_tuple(curr.first, curr.second, curr.first + 1, curr.second)) != sus.end() || sus.find(make_tuple(curr.first + 1, curr.second, curr.first, curr.second)) != sus.end())
                {
                    time += 1;
                }
                else
                {
                    time += 5;
                    sus.insert(make_tuple(curr.first + 1, curr.second, curr.first, curr.second));
                }
                curr = make_pair(curr.first + 1, curr.second);
            }
            else if (i == 'W')
            {
                if (sus.find(make_tuple(curr.first, curr.second, curr.first - 1, curr.second)) != sus.end() || sus.find(make_tuple(curr.first - 1, curr.second, curr.first, curr.second)) != sus.end())
                {
                    time += 1;
                }
                else
                {
                    time += 5;
                    sus.insert(make_tuple(curr.first - 1, curr.second, curr.first, curr.second));
                }
                curr = make_pair(curr.first - 1, curr.second);
            }
        }
        cout << time << "\n";
    }
}