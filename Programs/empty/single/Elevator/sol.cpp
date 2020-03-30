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
	int n, c;
	cin >> n >> c;
	int a[n - 1], b[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> b[i];
	}
	int dp[n][2];
	dp[0][0] = 0;
	dp[0][1] = c;
	cout << 0 << " ";
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = a[i - 1] + min(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = min(dp[i - 1][0] + b[i - 1] + c, dp[i - 1][1] + b[i - 1]);
		cout << min(dp[i][0], dp[i][1]) << " ";
	}
}