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

lll dp[101][101];

lll dynamic(lll n, lll d, lll k)
{
	if (n <= 0)
	{
		return 0;
	}
	lll ret = 0;
	if (n == 1)
	{
		if (d > 1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	for (int i = 1; i <= k; i++)
	{
		if (i < d)
		{
			ret += dynamic(n - i, d, k);
		}
		else
		{
			ret += ret + dynamic(n - i, 1, k);
		}
	}
	return ret;
}

int main()
{
	lll n, k, d;
	cin >> n >> k >> d;
	cout << "ans\n"
		 << dynamic(n, d, k);
}