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

bool check(lll x, lll n, lll a, lll b)
{
	return (x >= a * n + b * to_string(n).length());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll a, b, x;
	cin >> a >> b >> x;
	lll high = 1000000002;
	lll low = 0;
	lll med = (high + low) / 2;
	while (low <= high)
	{
		if (check(x, med, a, b))
		{
			low = med + 1;
			med = (high + low) / 2;
		}
		else
		{
			high = med - 1;
			med = (high + low) / 2;
		}
	}
	if (med >= 1000000000)
	{
		cout << 1000000000;
	}
	else
	{
		cout << med;
	}
}