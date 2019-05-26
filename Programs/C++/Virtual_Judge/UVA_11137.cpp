#include<bits/stdc++.h>
using namespace std;
int coins[22];
unsigned long long int ways(long long int n)
{
	unsigned long long int dp[n+1];
	for(int i = 0; i<n+1; i++)
	{
		dp[i] = 0;
	}
	dp[0] = 1;
	for(int j = 1; j <= 21; j++)
	{
		for(int i = coins[j]; i<=n; i++)
		{
			dp[i] += dp[i-coins[j]];
		}
	}
	return dp[n];
}
int main()
{
	for(int i = 1; i<=21; i++)
		coins[i] = i*i*i;
	long long int n;
	while(cin >> n)
	cout << ways(n) << "\n";
}