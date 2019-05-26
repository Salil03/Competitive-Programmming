#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	int b[n];
	int c[n];
	for(int i = 0; i<n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	int dp[n][3];
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];
	for(int i = 1; i<n; i++)
	{
		dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
	}
	cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}