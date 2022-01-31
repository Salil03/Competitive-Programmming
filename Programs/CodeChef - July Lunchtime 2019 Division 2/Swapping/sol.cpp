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
	long long int t;
	cin >> t;
	while (t--)
	{
		long long int n;
		cin >> n;
		long long int arr[n];
		for (long long int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		long long int dp[n + 1];
		dp[0] = 0;
		dp[1] = arr[0];
		for (long long int i = 2; i <= n; i++)
		{
			dp[i] = max(dp[i - 1] + arr[i - 1] * i, dp[i - 2] + arr[i - 1] * (i - 1) + arr[i - 2] * (i));
		}
		cout << dp[n] << "\n";
	}
}