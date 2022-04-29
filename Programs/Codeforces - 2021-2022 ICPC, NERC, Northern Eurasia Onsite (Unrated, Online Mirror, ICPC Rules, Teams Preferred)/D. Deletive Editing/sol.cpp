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

lll len1 = 0, len2 = 0;

bool recur(lll match, lll idx, string &a, string &b)
{
    bool flag = false;
    if (match == len2 - 1)
    {
        for (lll i = idx; i < len1; i++)
        {
            if (a[i] == b[match])
            {
                bool flag1 = true;
                for (lll j = i + 1; j < len1; j++)
                {
                    if (b.find(a[j]) != std::string::npos)
                    {
                        flag1 = false;
                        break;
                    }
                }
                flag |= flag1;
            }
        }
        return flag;
    }
    for (lll i = idx; i < len1; i++)
    {
        if (a[i] == b[match])
        {
            flag |= recur(match + 1, i + 1, a, b);
        }
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        len1 = a.length();
        len2 = b.length();
        bool flag = false;
        for (lll i = 0; i < len1; i++)
        {
            if (a[i] == b[0])
            {
                flag |= recur(1, i + 1, a, b);
            }
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}