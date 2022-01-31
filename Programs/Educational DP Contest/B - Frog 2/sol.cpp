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
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int dp[n];
	dp[0] = 0;
	dp[1] = abs(arr[1] - arr[0]);
	for (int i = 2; i < n; i++)
	{
		dp[i] = INT_MAX;
		for (int j = 1; j <= k; j++)
		{
			if (i - j < 0)
			{
				break;
			}
			dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
		}
	}
	cout << dp[n - 1];
}
