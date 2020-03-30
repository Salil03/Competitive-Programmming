//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
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

int dp[1000000][3];

int money(int day, int work)
{
	if (dp[day][work] != -1)
	{
		return dp[day][work];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = -1;
		dp[i][1] = -1;
		dp[i][2] = -1;
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][0] = arr[0];
	dp[1][1] = arr[0];
	dp[1][2] = arr[0];
	dp[2][0] = arr[1];
	dp[2][1] = arr[1];
	dp[2][2] = arr[1];
}