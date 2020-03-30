#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 100000000;
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
	long long int n;
	cin >> n;
	long long int arr[n];
	long long int cnt[100010] = {0};
	for (long long int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	long long int dp[100010];
	dp[0] = cnt[0] * 0;
	dp[1] = max(cnt[1] * 1, cnt[0]);
	dp[2] = max(dp[0] + cnt[2] * 2, dp[1]);
	for (long long int i = 3; i < 100010; i++)
	{
		dp[i] = max(dp[i - 2], dp[i - 3]) + cnt[i] * i;
	}
	cout << dp[100009];
}