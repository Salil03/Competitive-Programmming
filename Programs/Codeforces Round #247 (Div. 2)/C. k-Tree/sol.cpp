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

/*
$alil03

URL: url

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, d;
	cin >> n >> k >> d;
	lll dp[n + 1][n + 1] = {{0}};
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int t = 1; t <= k; t++)
			{
				if (t >= d && i - t >= 0 && j > 0)
				{
					dp[i][j] += dp[i - t][j - 1];
					dp[i][j] %= MOD;
				}
				else if (i - t >= 0 && t < d)
				{
					dp[i][j] += dp[i - t][j];
					dp[i][j] %= MOD;
				}
			}
		}
	}
	lll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += dp[n][i] % MOD;
	}
	cout << ans % MOD;
}