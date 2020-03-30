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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		lll arr[n][m];
		lll prefix[n][m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
				if (j == 0)
				{
					prefix[i][j] = arr[i][j];
				}
				else
				{
					prefix[i][j] = prefix[i][j - 1] + arr[i][j];
				}
			}
		}
		lll dp[m][m][n] = {{0}};
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int temp = 0; temp < n; temp++)
				{
					dp[i][j][temp] = INT_MIN;
				}
			}
		}
		for (int i = 0; i < m - k - 1; i++)
		{
			for (int j = i + k + 1; j < m; j++)
			{
				dp[i][j][n - 1] = prefix[n - 1][j] - prefix[n - 1][i] + arr[n - 1][i];
			}
		}
		if (k == 0)
		{
			for (int row = n - 2; row >= 0; row--)
			{
				for (int i = 0; i < m - k - 1; i++)
				{
					for (int j = i + k + 1; j < m; j++)
					{
						dp[i][j][row] = prefix[j] - prefix[i] + dp[i][j][row + 1];
					}
				}
			}
			lll maximum = INT_MIN;
			for (int i = 0; i < m - k - 1; i++)
			{
				for (int j = i + k + 1; j < m; j++)
				{
					maximum = max(maximum, dp[i][j][0]);
				}
			}
			cout << maximum << "\n";
			continue;
		}
		for (int row = n - 2; row >= 0; row--)
		{
			for (int i = 0; i < m - 1; i++)
			{
				for (int j = i + 1; j < m; j++)
				{
					if (j - i == 1)
					{
						if (j == m - 1)
						{
							dp[i][j][row] = dp[i][j][row + 1] + prefix[row][j] - prefix[row][i] + arr[row][i];
							continue;
						}
						dp[i][j][row] = max({dp[i + 1][j + 1][row + 1], dp[i][j + 1][row + 1], dp[i][j][row + 1]}) + prefix[row][j] - prefix[row][i] + arr[row][i];
						continue;
					}
					if (j == m - 1)
					{
						dp[i][j][row] = max({dp[i][j][row + 1], dp[i + 1][j][row + 1]}) + prefix[row][j] - prefix[row][i] + arr[row][i];
						continue;
					}
					dp[i][j][row] = max({dp[i + 1][j + 1][row + 1], dp[i][j + 1][row + 1], dp[i][j][row + 1], dp[i + 1][j][row + 1]}) + prefix[row][j] - prefix[row][i] + arr[row][i];
				}
			}
		}
		lll maximum = INT_MIN;
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = i + 1; j < m; j++)
			{
				maximum = max(maximum, dp[i][j][0]);
			}
		}
		cout << maximum << "\n";
	}
}