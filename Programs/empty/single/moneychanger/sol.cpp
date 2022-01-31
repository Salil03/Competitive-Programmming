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
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
lll n, v;
lll table[10010];

lll dp(lll rem, lll coins[])
{
	if (rem == 0)
	{
		return 0;
	}
	if (rem < 0)
	{
		return INT_MAX;
	}
	if (table[rem] != -1)
	{
		return table[rem];
	}
	lll ans = INT_MAX;
	for (lll i = 0; i < n; i++)
	{
		ans = min(ans, 1 + dp(rem - coins[i], coins));
	}
	return table[rem] = ans;
}

int main()
{
	cin >> n >> v;
	lll coins[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> coins[i];
	}
	memset(table, -1, sizeof table);
	if (dp(v, coins) >= INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << dp(v, coins);
	}
}