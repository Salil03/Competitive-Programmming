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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int dp[n];
		dp[0] = 1;
		for (int i = 1; i < n; i++)
		{
			dp[i] = 1;
			for (int k = i - 1; k >= 0; k--)
			{
				if (arr[k] <= arr[i])
				{
					dp[i] = max(dp[i], dp[k] + 1);
				}
			}
		}
		cout << *max_element(dp, dp + n) << "\n";
	}
}