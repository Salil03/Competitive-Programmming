//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

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
	int t;
	cin >> t;
	while (t--)
	{
		int h, w;
		cin >> h >> w;
		int arr[h][w];
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
		int dp[h][w];
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < w; i++)
		{
			dp[0][i] = arr[0][i];
		}
		for (int i = 1; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (j == 0)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
				}
				else if (j == w - 1)
				{
					dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
				}
				else
				{
					dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});
				}
				dp[i][j] += arr[i][j];
			}
		}
		int maximum = -1;
		for (int i = 0; i < w; i++)
		{
			maximum = max(maximum, dp[h - 1][i]);
		}
		cout << maximum << "\n";
	}
}