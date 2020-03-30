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
	lll n, m;
	cin >> n >> m;
	lll arr[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	bool safe[n][n] = {};
	while (m--)
	{
		lll x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		for (int i = max((lll)0, x - z - 1); i < min(n, x + z + 1); i++)
		{
			for (int j = min((lll)0, y - z - 1); j < min(n, y + z + 1); j++)
			{
				if (abs(i - x) + abs(j - y) <= z)
				{
					safe[i][j] = 1;
				}
			}
		}
	}
	lll dp[n][n] = {};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = -5000000;
		}
	}
	if (!safe[0][0])
	{
		cout << "NO";
		return 0;
	}
	dp[0][0] = arr[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!safe[i][j])
			{
				continue;
			}
			if (i > 0)
			{
				if (safe[i - 1][j])
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
			}
			if (j > 0)
			{
				if (safe[i][j - 1])
					dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i][j]);
			}
		}
	}
	if (dp[n - 1][n - 1] <= -5000000)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n";
		cout << dp[n - 1][n - 1];
	}
}