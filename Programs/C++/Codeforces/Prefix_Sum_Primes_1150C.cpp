#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://codeforces.com/contest/1150/problem/C

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int sieve[400004];
	memset(sieve, 0, sizeof(sieve)); //initialize to zero
	for (int x = 2; x * x <= 400003; x++)
	{
		if (sieve[x])
			continue;
		for (int u = x * x; u <= 400003; u += x)
		{
			sieve[u] = x;
		}
	}
	for (int i = 2; i <= 400003; i++)
	{
		if (!sieve[i])
			cout << i << "\n";
	}
	int one = 0;
	int two = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 1)
		{
			one++;
		}
		else
		{
			two++;
		}
	}
	//dp[0] = 1;
	//dp[1] = 2;
	pair<int, int> dp[n + 1][2];
	if (one)
	{
		dp[1][0] = {0, 1};
	}
	if (two)
	{
		dp[1][1] = {1, 2};
	}
	int i = 2;
	while (one || two)
	{
		if (one)
		{
			if (sieve[dp[i - 1][0].first + 1])
			{
				dp[i][0] = {dp[i - 1].first + 1, dp[i - 1].second + 1};
			}
			if (sieve[dp[i - 1][0].first + 2])
			{
				dp[i][0] = {dp[i - 1].first + 1, dp[i - 1].second + 1};
			}
		}
	}
}