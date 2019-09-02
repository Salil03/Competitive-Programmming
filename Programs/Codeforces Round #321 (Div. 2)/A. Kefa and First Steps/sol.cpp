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
	int maximum = -2;
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i - 1] >= arr[i - 2])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			maximum = max(maximum, dp[i - 1]);
			dp[i] = 1;
		}
	}
	maximum = max(maximum, dp[n]);
	cout << maximum;
}