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
	lll n;
	cin >> n;
	lll arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	pair<lll, lll> dp[n] = {};
	if (arr[0] > 0)
	{
		dp[0].first = arr[0];
		dp[0].second = 1;
	}
	else
	{
		dp[0].first = 0;
		dp[0].second = 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1].second & 1)
		{
			dp[i].first = dp[i - 1].first - arr[i];
		}
		else
		{
			dp[i].first = dp[i - 1].first + arr[i];
		}
		dp[i].second = dp[i - 1].second + 1;
		if (arr[i] > dp[i].first)
		{
			dp[i].second = 1;
			dp[i].first = arr[i];
		}
	}
	lll maximum = 0;
	for (int i = 0; i < n; i++)
	{
		maximum = max(maximum, dp[i].first);
	}
	cout << maximum;
}