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
lll n, k;
lll table[10010][110];
lll dp(lll idx, lll drop, lll arr[])
{
	if (idx == n)
	{
		return 0;
	}
	if (table[idx][drop] != -1)
	{
		return table[idx][drop];
	}
	if (drop == 0)
	{
		return table[idx][drop] = max(arr[idx] + dp(idx + 1, 0, arr), 0LL);
	}
	return table[idx][drop] = max({dp(idx + 1, drop - 1, arr), arr[idx] + dp(idx + 1, drop, arr), 0LL});
}

int main()
{
	cin >> n >> k;
	lll arr[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	lll maximum = -INF;
	memset(table, -1, sizeof table);
	for (lll i = 0; i < n; i++)
	{
		maximum = max(maximum, dp(i, k, arr));
	}
	cout << maximum << "\n";
}