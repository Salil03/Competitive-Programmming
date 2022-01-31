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

#define watch(x) cout << "\n" \
					  << (#x) << " is " << (x) << endl
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

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
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int dp[n][2] = {{0}};
		dp[n - 1][0] = 1;
		dp[n - 1][1] = 1;
		for (int i = n - 2; i >= 0; i--)
		{
			if (arr[i] > arr[i + 1])
			{
				dp[i][0] = 1;
				dp[i][1] = 1 + dp[i + 1][0];
			}
			else if (arr[i] < arr[i + 1])
			{
				dp[i][1] = 1;
				dp[i][0] = 1 + dp[i + 1][1];
			}
			else if (arr[i] == arr[i + 1])
			{
				dp[i][0] = 1 + dp[i + 1][1];
				dp[i][1] = 1 + dp[i + 1][0];
			}
		}
		int maximum = -1;
		for (int i = 0; i < n; i++)
		{
			if (i + dp[i][0] == n)
			{
				maximum = max(maximum, dp[i][0] + 1);
			}
			else if (dp[i][0] & 1)
			{
				maximum = max(maximum, 1 + dp[i][0] + dp[i + dp[i][0]][0]);
			}
			else
			{
				maximum = max(maximum, 1 + dp[i][0] + dp[i + dp[i][0]][1]);
			}
		}
		cout << maximum << "\n";
	}
}