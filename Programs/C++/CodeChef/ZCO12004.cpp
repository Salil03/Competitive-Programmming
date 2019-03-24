#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const long long int INF = 0x3f3f3f3f;
const long long int MOD = 1000000007;

/*
$alil03
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
	for(long long int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	long long int dp[n];
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	for(int i = 2; i<n; i++)
	{
		dp[i] = arr[i] + min(dp[i-1], dp[i-2]);
	}
	long long int ans1 = min(dp[n-1], dp[n-2]);
	dp[0] = arr[0];
	dp[1] = arr[1];
	for(int i = 2; i<n; i++)
	{
		dp[i] = arr[i] + min(dp[i-1], dp[i-2]);
	}
	long long  int ans2 = dp[n-1];
	cout << min(ans1, ans2);
}