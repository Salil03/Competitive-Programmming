//https://codeforces.com/problemset/problem/474/D
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, k;
	cin >> t >> k;
	int a[t], b[t];
	for (int i = 0; i < t; i++)
	{
		cin >> a[i] >> b[i];
	}
	int maximum = *max_element(b, b + t);
	lll dp[maximum + 1];
	for (int i = 0; i <= maximum; i++)
	{
		if (i >= k)
		{
			dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
		}
		else
		{
			dp[i] = 1;
		}
	}
	lll prefix[maximum + 1];
	prefix[0] = dp[0];
	for (int i = 1; i <= maximum; i++)
	{
		prefix[i] = (dp[i] + prefix[i - 1]) % MOD;
	}
	for (int i = 0; i < t; i++)
	{
		cout << (prefix[b[i]] - prefix[a[i] - 1]) % MOD << "\n";
	}
}