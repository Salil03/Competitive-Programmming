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
lll table[110][110] = {};
int dp(int left, int right, string s)
{
	if (left == right)
	{
		return 0;
	}
	if (left == right - 1)
	{
		if (s[left] == s[right])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (table[left][right] != -1)
	{
		return table[left][right];
	}
	if (s[left] == s[right])
	{
		return table[left][right] = dp(left + 1, right - 1, s);
	}
	else
	{
		return table[left][right] = 1 + min(dp(left, right - 1, s), dp(left + 1, right, s));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		string s;
		cin >> s;
		lll n = s.length();
		for (int i = 0; i <= n + 2; i++)
		{
			for (int j = 0; j <= n + 2; j++)
			{
				table[i][j] = -1;
			}
		}
		cout << "Case " << k << ": " << dp(0, n - 1, s) << "\n";
	}
}