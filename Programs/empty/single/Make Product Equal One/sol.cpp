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
lll n;
lll table[100010][2];
lll dp(lll idx, bool parity, lll arr[])
{
	if (idx == n)
	{
		if (!parity)
		{
			return 0;
		}
		else
		{
			return INT_MAX;
		}
	}
	if (table[idx][parity] != -1)
	{
		return table[idx][parity];
	}
	return table[idx][parity] = min(abs(-1 - arr[idx]) + dp(idx + 1, !parity, arr), abs(1 - arr[idx]) + dp(idx + 1, parity, arr));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	lll arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	memset(table, -1, sizeof table);
	cout << dp(0, 0, arr);
}