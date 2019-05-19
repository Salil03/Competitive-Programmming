#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://codeforces.com/problemset/problem/368/B

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int dp[n] = {0};
	dp[n - 1]++;
	set<int> distinct;
	distinct.insert(arr[n - 1]);
	for (int i = n - 2; i >= 0; i--)
	{
		dp[i] = dp[i + 1];
		if (!(distinct.find(arr[i]) != distinct.end()))
		{
			distinct.insert(arr[i]);
			dp[i]++;
		}
	}
	while (m--)
	{
		int temp;
		cin >> temp;
		cout << dp[temp - 1] << "\n";
	}
}