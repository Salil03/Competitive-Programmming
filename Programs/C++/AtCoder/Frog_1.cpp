#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	long long heights[n];
	for(long long i = 0; i<n; i++)
	{
		cin >> heights[i];
	}
	long long dp[n];
	dp[0] = 0;
	for(long long i = 1; i<n; i++)
	{
		dp[i] = min(dp[i-1] + abs(heights[i] - heights[i-1]), dp[i-2] + abs(heights[i] - heights[i-2]));
	}
	cout << dp[n-1];
}