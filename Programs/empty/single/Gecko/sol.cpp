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
	lll h, w;
	cin >> h >> w;
	lll arr[h][w];
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
		}
	}
	lll dp[h][w] = {};
	for (int i = 0; i < w; i++)
	{
		dp[0][i] = arr[0][i];
	}
	for (int i = 1; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (j > 0 && j < w - 1)
			{
				dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});
			}
			else if (j == 0 && j < w - 1)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
			}
			else if (j == w - 1 && j > 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
			dp[i][j] += arr[i][j];
		}
	}
	lll maximum = 0;
	for (int i = 0; i < w; i++)
	{
		maximum = max(maximum, dp[h - 1][i]);
	}
	cout << maximum;
}