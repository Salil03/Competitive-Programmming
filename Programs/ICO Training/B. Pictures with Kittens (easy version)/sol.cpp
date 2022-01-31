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
int main()
{
	lll n, k, x;
	cin >> n >> k >> x;
	lll arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	lll dp[n + 1][x + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			dp[i][j] = -INF;
		}
	}

	dp[0][x] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < x; j++)
		{
			for (int p = 1; p <= k; p++)
			{
				if (i - p < 0)
					break;
				if (dp[i - p][j + 1] == -INF)
				{
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[i - p][j + 1] + arr[i - 1]);
			}
		}
	}

	long long ans = -INF;
	for (int i = n - k + 1; i <= n; ++i)
	{
		for (int j = 0; j <= x; j++)
		{
			ans = max(ans, dp[i][j]);
		}
	}
	if (ans == -INF)
		ans = -1;
	cout << ans << endl;

	return 0;
}