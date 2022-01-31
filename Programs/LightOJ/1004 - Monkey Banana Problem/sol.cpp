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
	for (int temp = 1; temp <= t; temp++)
	{
		int n;
		cin >> n;
		int arr[2 * n - 1][n] = {{0}}; // n = 4
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = n; i < 2 * n - 1; i++)
		{
			for (int j = 0; j < 2 * n - i - 1; j++)
			{
				cin >> arr[i][j];
			}
		}
		int dp[2 * n - 1][n] = {{0}};
		dp[0][0] = arr[0][0];
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
				{
					dp[i][j] = arr[i][j] + dp[i - 1][j];
				}
				else if (j == i)
				{
					dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
				}
			}
		}
		for (int i = n; i < 2 * n - 1; i++)
		{
			for (int j = 0; j < 2 * n - i - 1; j++)
			{
				dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j + 1]);
			}
		}
		cout << "Case " << temp << ": " << dp[2 * n - 2][0] << "\n";
	}
}