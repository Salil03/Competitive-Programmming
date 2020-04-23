//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#define watch(x) cerr << "\n" \
                      << (#x) << " is " << (x) << endl
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
string s;
lll table[1010][1010];
lll dp(int left, int right, int n)
{
    if (left >= right)
    {
        return 0;
    }
    if (table[left][right] != -1)
    {
        return table[left][right];
    }
    if (right - left <= 4)
    {
        return table[left][right] = 0;
    }
    if ((s[left] == 'A' && s[right] == 'U') || (s[left] == 'U' && s[right] == 'A') || (s[left] == 'C' && s[right] == 'G') || (s[left] == 'G' && s[right] == 'C'))
    {
        return table[left][right] = max({1 + dp(left + 1, right - 1, n), dp(left + 1, right, n), dp(left, right - 1, n)});
    }
    else
    {
        return table[left][right] = max(dp(left + 1, right, n), dp(left, right - 1, n));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int n = s.length();
        memset(table, -1, sizeof table);
        cout << dp(0, n - 1, n) << "\n";
    }
}