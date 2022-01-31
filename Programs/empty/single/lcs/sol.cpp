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
string a, b;
int table[1010][1010];
int dp(int x, int y, int m, int n)
{
	if (x == m || y == n)
	{
		return 0;
	}
	if (table[x][y] != -1)
	{
		return table[x][y];
	}
	if (a[x] == b[y])
	{
		return table[x][y] = max({1 + dp(x + 1, y + 1, m, n), dp(x + 1, y, m, n), dp(x, y + 1, m, n)});
	}
	else
	{
		return table[x][y] = max(dp(x + 1, y, m, n), dp(x, y + 1, m, n));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	memset(table, -1, sizeof table);
	cout << dp(0, 0, a.length(), b.length());
}