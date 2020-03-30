//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

int table[2010][2010] = {{0}};
int dp(pair<int, int> arr[], int rem, int curr, int n)
{
	if (table[curr][rem] != -1)
	{
		return table[curr][rem];
	}
	if (arr[curr].first > rem)
	{
		table[curr][rem] = dp(arr, rem, curr + 1, n);
		return table[curr][rem];
	}
	table[curr][rem] = max(dp(arr, rem, curr + 1, n), arr[curr].second + dp(arr, rem - arr[curr].first, curr + 1, n));
	return table[curr][rem];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int s, n;
	cin >> s >> n;
	pair<int, int> arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0; i <= n + 2; i++)
	{
		for (int j = 0; j <= s + 2; j++)
		{
			if (i == n || j == 0)
			{
				table[i][j] = 0;
			}
			else
			{
				table[i][j] = -1;
			}
		}
	}
	cout << dp(arr, s, 0, n);
}