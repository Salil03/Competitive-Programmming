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
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			return 0;
		}
		int m;
		cin >> m;
		long long int arr[n][m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		long long int dp[n][m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == 0 && j == 0)
				{
					dp[i][j] = arr[0][0];
				}
				else if (i == 0)
				{
					dp[i][j] = arr[i][j] + min({dp[0][j - 1], dp[1][j], dp[0][j + 1]});
				}
				else if (j == 0)
				{
					dp[i][j] = arr[i][j] + min({dp[i - 1][0], dp[i][1], dp[i + 1][0]});
				}
				else
				{
					dp[i][j] = arr[i][j] + min({dp[i - 1][j], dp[i][j - 1], dp[i + 1][j], dp[i][j + 1]});
				}
			}
		}
		cout << dp[n - 1][m - 1] << "\n";
	}
}