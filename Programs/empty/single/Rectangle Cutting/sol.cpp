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

int table[510][510];

int dp(int a, int b)
{
	if (a == b)
	{
		return 0;
	}
	if (table[a][b] != -1)
	{
		return table[a][b];
	}
	int ans = INT_MAX;
	for (int i = 1; i < a; i++)
	{
		ans = min(ans, 1 + dp(i, b) + dp(a - i, b));
	}
	for (int i = 1; i < b; i++)
	{
		ans = min(ans, 1 + dp(a, i) + dp(a, b - i));
	}
	return table[a][b] = ans;
}

int main()
{
	int a, b;
	cin >> a >> b;
	memset(table, -1, sizeof table);
	cout << dp(a, b);
}