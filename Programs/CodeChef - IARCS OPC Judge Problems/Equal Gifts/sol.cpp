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
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[i] = abs(x - y);
	}
	bool dp[n][45004] = {{0}};
	dp[0][arr[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 45004 - arr[i]; j++)
		{
			if (dp[i - 1][abs(j - arr[i])] || dp[i - 1][j + arr[i]])
			{
				dp[i][j] = true;
			}
		}
	}
	int minimum = INT_MAX;
	for (int i = 0; i < 45004; i++)
	{
		if (dp[n - 1][i])
		{
			minimum = min(minimum, i);
		}
	}
	cout << minimum;
}