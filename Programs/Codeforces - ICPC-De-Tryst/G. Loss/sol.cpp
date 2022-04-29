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

lll minimum = INT_MAX;
string curr = to_string(INT_MAX);

bool compare_string(string &a, string &b) // check if a >= b
{
    if (a.length() > b.length())
    {
        return true;
    }
    else if (a.length() < b.length())
    {
        return false;
    }
    else
    {
        lll len = a.length();
        for (lll i = 0; i < len; i++)
        {
            if (a[i] > b[i])
            {
                return true;
            }
            else if (b[i] > a[i])
            {
                return false;
            }
        }
    }
    return true;
}

lll cost(string &ans)
{
    lll one = count(ans.begin(), ans.end(), '1');
    lll two = count(ans.begin(), ans.end(), '2');
    lll three = count(ans.begin(), ans.end(), '3');
    return (abs(one - two) + abs(two - three) + abs(three - one) + ans.length());
}
string s;
void smallest(string ans)
{
    if (ans.length() == 14)
    {
        return;
    }
    if (compare_string(ans, s))
    {
        lll loss = cost(ans);
        if (minimum > loss)
        {
            minimum = loss;
            curr = ans;
        }
        else if (minimum == loss)
        {
            if (compare_string(curr, ans))
            {
                curr = ans;
            }
        }
    }
    smallest(ans + "1");
    smallest(ans + "2");
    smallest(ans + "3");
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin >> s;
    string temp = "";
    smallest("");
    cout << curr;
}