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
const long long int INF = 0x3f3f3f3f3f3f3f3f;

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
	uuu r, c;
	cin >> r >> c;
	lll dp[r][r];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 1; i < r; i++)
	{
		for (int j = 0; j < r + 1; j++)
		{
			if (j < r)
			{
				dp[i][j] += dp[i - 1][j];
			}
			if (j > 0)
			{
				dp[i][j] += dp[i - 1][j - 1];
			}
		}
	}
	cout << dp[r - 1][c - 1];
}