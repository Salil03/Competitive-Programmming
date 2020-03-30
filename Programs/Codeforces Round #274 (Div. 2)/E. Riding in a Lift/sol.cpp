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

lll table[5006][5006] = {{0}};
lll dp(lll source, lll n, lll b, lll k)
{
	lll ans = 0;
	if (table[source][k] != -1)
	{
		return table[source][k];
	}
	for (lll i = source + 1; i < min(source + abs(b - source), n); i++)
	{
		ans += dp(i, n, b, k - 1) % MOD;
	}
	for (lll i = source - 1; i > max(source - abs(b - source), (lll)-1); i--)
	{
		ans += dp(i, n, b, k - 1) % MOD;
	}
	return table[source][k] = ans % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n, a, b, k;
	cin >> n >> a >> b >> k;
	for (lll i = 0; i < n + 2; i++)
	{
		for (lll j = 0; j < k + 2; j++)
		{
			table[i][j] = -1;
		}
	}
	for (lll i = 0; i < n + 2; i++)
	{
		table[i][0] = 1;
	}
	cout << dp(a - 1, n, b - 1, k) % MOD;
}