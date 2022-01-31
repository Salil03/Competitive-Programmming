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
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: url

Solution Begins here
*/

int main()
{
	int n, k;
	cin >> n >> k;
	k /= 2;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int dp[n][k + 1];
	for (int i = 0; i <= k; i++)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			int maximum = INT_MIN;
			for (int t = 0; t < i; t++)
			{
				maximum = max(maximum, dp[t][j - 1] + arr[i] - arr[t]);
			}
			dp[i][j] = max(maximum, dp[i - 1][j]);
		}
	}
	int ans = -2;
	for (int i = 0; i <= k; i++)
	{
		ans = max(ans, dp[n - 1][i]);
	}
	cout << ans;
}
