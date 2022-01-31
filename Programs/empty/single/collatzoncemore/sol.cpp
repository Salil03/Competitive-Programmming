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

lll fib[30];

lll dp(lll idx)
{
	if (fib[idx] != -1)
	{
		return fib[idx];
	}
	return fib[idx] = dp(idx - 1) + dp(idx - 2);
}

lll collatz(lll num)
{
	if (binary_search(fib, fib + 30, num))
	{
		return 0;
	}
	if (num & 1)
	{
		return 1 + collatz(3 * num + 1);
	}
	else
	{
		return 1 + collatz(num / 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(fib, -1, sizeof fib);
	fib[0] = 0;
	fib[1] = 1;
	dp(29);
	lll n;
	cin >> n;
	cout << collatz(n);
}