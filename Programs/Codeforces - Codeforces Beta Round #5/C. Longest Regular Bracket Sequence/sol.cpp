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
    stack<pair<char, lll>> bracket;
    lll n = s.length();
    vector<lll> open(n, -1), open_first(n, -1);
    for (lll i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            bracket.push(make_pair(s[i], i));
        }
        else if (s[i] == ')' && bracket.empty())
        {
            open[i] = -1;
            open_first[i] = -1;
        }
        else if (s[i] == ')' && !bracket.empty())
        {
            open[i] = bracket.top().second;
            bracket.pop();
            if (open[i] == 0)
            {
                open_first[i] = open[i];
            }
            else if (open_first[open[i] - 1] == -1)
            {
                open_first[i] = open[i];
            }
            else
            {
                open_first[i] = open_first[open[i] - 1];
            }
        }
    }
    // dbg(open);
    // dbg(open_first);
    lll maximum = 0, curr = 1;
    for (lll i = 0; i < n; i++)
    {
        if (open_first[i] == -1)
        {
            continue;
        }
        if (maximum == i - open_first[i] + 1)
        {
            curr++;
        }
        else if (maximum < i - open_first[i] + 1)
        {
            maximum = i - open_first[i] + 1;
            curr = 1;
        }
    }
    cout << maximum << " " << curr;
}