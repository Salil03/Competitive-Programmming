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

lll minima(lll div1, lll div2)
{
	if (__gcd(div1, div2) == 1)
	{
		return max(div1, div2);
	}
	return 10e13;
}

int main()
{
	lll x;
	cin >> x;
	lll minimum = 10e13;
	lll a = -1, b = -1;
	for (lll i = 1; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			if (minima(i, x / i) < minimum)
			{
				minimum = minima(i, x / i);
				a = i;
				b = x / i;
			}
		}
	}
	cout << a << " " << b;
}