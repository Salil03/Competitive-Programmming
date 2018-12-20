#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
	int dp[n +1];
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i<=n; i++)
	{
		dp[i] = dp[i-1]%15746 + dp[i-2]%15746;
	}
	return dp[n]%15746;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cout << fibo(n)%15746;
}