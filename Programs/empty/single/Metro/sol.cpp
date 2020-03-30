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
	int k;
	cin >> k;
	bool arr[n][m] = {};
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		arr[x][y] = 1;
	}
	float dp[n + 1][m + 1][k + 1] = {};
	dp[0][0][0] = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			for (int l = 0; l <= k; l++)
			{
				dp[i][j][l] = INT_MAX;
				if (i > 0)
				{
					dp[i][j][l] = min(dp[i][j][l], dp[i - 1][j][l] + 100);
				}
				if (j > 0)
				{
					dp[i][j][l] = min(dp[i][j][l], dp[i][j - 1][l] + 100);
				}
				if (i > 0 && j > 0 && l > 0)
				{
					if (arr[i - 1][j - 1])
					{
						dp[i][j][l] = min(dp[i][j][l], dp[i - 1][j - 1][l - 1] + 100 * (float)sqrt(2));
					}
				}
			}
		}
	}
	float ans = INT_MAX;
	for (int i = 0; i <= k; i++)
	{
		ans = min(ans, dp[n][m][i]);
	}
	cout << round(ans);
}