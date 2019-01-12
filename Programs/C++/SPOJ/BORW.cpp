#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	while(cin >> n)
	{
		if(n==-1)
			return 0;
		int arr[n];
		for(int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		int dp[n+1][3];
		//dp[i][0] is unpainted
		//dp[i][1] is black
		//dp[i][2] is white
		for(int i = 0; i<=n; i++)
		{
			dp[i][0] = INT_MAX;
			dp[i][1] = INT_MAX;
			dp[i][2] = INT_MAX;
		}
		dp[0][0] = 1;
		dp[0][1] = 0;
		dp[0][2] = 0;
		for(int i = 1; i<=n; i++)
		{
			if(arr[i] > arr[i-1])
			{
				dp[i][0] = 1+min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
				dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
			}
			if(arr[i] < arr[i-1])
			{
				dp[i][0] = 1+min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
				dp[i][2] = min(dp[i-1][0], dp[i-1][2]);
			}
			if(arr[i] == arr[i-1])
			{
				dp[i][0] = 1+min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
			}
		}
		cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";;
	}
}