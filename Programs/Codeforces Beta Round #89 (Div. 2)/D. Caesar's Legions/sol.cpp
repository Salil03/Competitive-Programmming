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
const int MOD = 100000000;
const int INF = 0x3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
int n1, n2, k1, k2;
ll table[110][110][14][14];
int dp(int f, int h, int kf, int kh)
{
	if (f + h == 0)
	{
		return 1;
	}
	if (f + h > 0)
	{
		if (table[f][h][kf][kh] != -1)
		{
			return table[f][h][kf][kh] % MOD;
		}
		ll ans = 0;
		if (f > 0 && kf > 0)
		{
			ans += dp(f - 1, h, kf - 1, k2);
		}
		if (h > 0 && kh > 0)
		{
			ans += dp(f, h - 1, k1, kh - 1);
		}
		return table[f][h][kf][kh] = (ans % MOD);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n1 >> n2 >> k1 >> k2;
	memset(table, -1, sizeof table);
	cout << dp(n1, n2, k1, k2) % MOD;
}