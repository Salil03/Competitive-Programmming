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

/*
$alil03

URL: url

Solution Begins here
*/

lll dp[710][710];

lll recur(lll left, lll right, lll k, lll v[], lll b[])
{
	if (left >= right)
	{
		return 0;
	}
	if (left == right - 1)
	{
		if (b[right] - b[left] == k)
		{
			return max(0LL, v[left] + v[right]);
		}
		return 0;
	}
	if (dp[left][right] != -1)
	{
		return dp[left][right];
	}
	lll ans = recur(left + 1, right, k, v, b);
	for (lll i = left + 1; i <= right; i++)
	{
		if (b[i] - b[left] == k)
		{
			ans = max(ans, v[left] + recur(left + 1, i - 1, k, v, b) + v[i] + recur(i + 1, right, k, v, b));
		}
	}
	return dp[left][right] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n, k;
	cin >> n >> k;
	lll v[n], b[n];
	memset(dp, -1, sizeof dp);
	for (lll i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (lll i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	cout << recur(0, n - 1, k, v, b);
}