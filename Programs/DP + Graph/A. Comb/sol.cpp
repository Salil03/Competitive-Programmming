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
const int INF = 0x3f3f3f3f;

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
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			arr[i][j] += arr[i][j - 1];
		}
	}
	int dp[n][m] = {{0}};
	for (int i = 0; i < m; i++)
	{
		dp[0][i] = arr[0][i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i & 1)
			{
				if (j == m - 1)
				{
					dp[i][j] = INT_MIN;
					continue;
				}
				dp[i][j] = arr[i][j] + dp[i - 1][j + 1];
				for (int k = j + 2; k < m; k++)
				{
					dp[i][j] = max(dp[i][j], arr[i][j] + dp[i - 1][k]);
				}
			}
			else
			{
				if (j == 0)
				{
					dp[i][j] = INT_MIN;
					continue;
				}
				dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
				for (int k = 0; k <= j - 2; k++)
				{
					dp[i][j] = max(dp[i][j], arr[i][j] + dp[i - 1][k]);
				}
			}
		}
	}
	int maximum = INT_MIN;
	for (int i = 0; i < m; i++)
	{
		maximum = max(maximum, dp[n - 1][i]);
	}
	cout << maximum;
}