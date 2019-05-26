#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,k;
	cin >> n >>k;
	long long heights[n];
	for(long long i = 0; i<n; i++)
	{
		cin >> heights[i];
	}
	long long dp[n];
	for(int i = 0; i<n; i++)
	{
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for(long long i = 1; i<n; i++)
	{
		for(long long j = 1; j<=k; j++)
		{
			if(i - j < 0)
			{
				break;
			}
			dp[i] = min(dp[i-j] + abs(heights[i] - heights[i-j]), dp[i]);
		}
	}
	cout << dp[n-1];
}