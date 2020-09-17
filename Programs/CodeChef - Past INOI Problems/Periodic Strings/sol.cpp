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

lll modular(lll n, lll m)
{
	if (n == 1)
	{
		return 2;
	}
	if (n & 1)
	{
		return (modular(n / 2, m) * modular(n / 2, m) * 2) % m;
	}
	else
	{
		return (modular(n / 2, m) * modular(n / 2, m)) % m;
	}
}

lll dp(lll n, lll m)
{
	lll ans = 2;
	for (lll i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			ans += dp(i, m) % m;
			ans += dp(n / i, m) % m;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n, m;
	cin >> n >> m;
	cout << dp(n, m);
}