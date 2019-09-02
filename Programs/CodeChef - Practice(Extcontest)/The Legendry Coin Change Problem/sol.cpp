#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
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
	int n, m;
	cin >> n >> m;
	int arr[m];
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + m);
	int dp[n + 1] = {0};
	for (int i : arr)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i + j > n)
			{
				break;
			}
			dp[i + j]++;
		}
	}
	cout << dp[n] + 1;
}