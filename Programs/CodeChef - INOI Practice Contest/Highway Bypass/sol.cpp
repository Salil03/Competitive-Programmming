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
ll dp[305][305][305][2] = {};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int r, c, d;
	cin >> r >> c >> d;
	bool grid[r + 1][c + 1] = {{0}};
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> grid[i][j];
		}
	}
	if (grid[r][c])
	{
		for (int i = 0; i <= d; i++)
		{
			dp[r][c][i][0] = 1;
			dp[r][c][i][1] = 1;
		}
	}
	for (int i = r; i >= 1; i--)
	{
		for (int j = c; j >= 1; j--)
		{
			if (i == r && j == c)
			{
				continue;
			}
			if (!grid[i][j])
			{
				continue;
			}
			for (int k = 0; k <= d; k++)
			{
				if (k == d)
				{
					dp[i][j][d][1] = dp[i][j + 1][1][0] % 20011;
					dp[i][j][d][0] = dp[i + 1][j][1][1] % 20011;
					continue;
				}
				dp[i][j][k][1] = (dp[i + 1][j][k + 1][1] + dp[i][j + 1][1][0]) % 20011;
				dp[i][j][k][0] = (dp[i + 1][j][1][1] + dp[i][j + 1][k + 1][0]) % 20011;
			}
		}
	}
	cout << dp[1][1][0][1] % 20011;
}