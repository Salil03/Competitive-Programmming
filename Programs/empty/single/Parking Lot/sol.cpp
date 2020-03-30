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

lll recur2(lll idx, lll num)
{
	if (idx == num - 1)
	{
		return 3;
	}
	else
	{
		return 4 * recur2(idx + 1, num);
	}
}
lll recur1(lll idx, lll num)
{
	if (idx == num + 1)
	{
		return 3;
	}
	else
	{
		return 4 * recur1(idx - 1, num);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n;
	cin >> n;
	lll ans = 0;
	ans += recur1(2 * n - 3, n - 1);
	ans += recur2(0, n - 2);
	for (int i = 1; i < n - 2; i++)
	{
		ans += recur2(0, i + 1);
		ans += recur1(2 * n - 3, i + n - 1);
	}
	cout << ans * 4;
}