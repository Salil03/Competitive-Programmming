//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
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
map<long long int, long long int> table;
long long int dp(long long int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (table[n] != 0)
	{
		return table[n];
	}
	else
	{
		table[n] = max(n, dp(n / 2) + dp(n / 3) + dp(n / 4));
		return table[n];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	table[0] = 0;
	long long int n;
	while (cin >> n)
	{
		cout << dp(n) << "\n";
	}
}