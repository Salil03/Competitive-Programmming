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

lll dp(lll idx, lll last, vector<lll> p[], vector<lll> c[], lll n, lll m)
{
	if (idx == n)
	{
		return 0;
	}
	lll ans = INF;
	for (lll i = 0; i < m; i++)
	{
		if (i == last)
		{
			ans = min(ans, max(0LL, p[idx][i] - c[idx][i]) + dp(idx + 1, i, p, c, n, m));
		}
		else
		{
			ans = min(ans, p[idx][i] + dp(idx + 1, i, p, c, n, m));
		}
		cout << idx << " " << i << " " << ans << "\n";
	}
	return ans;
}

int main()
{
	lll t;
	cin >> t;
	while (t--)
	{
		lll n, m;
		cin >> n >> m;
		vector<lll> p[n]; //item // shop
		vector<lll> c[n];
		for (int i = 0; i < n; i++)
		{
			p[i].resize(m);
			for (int j = 0; j < m; j++)
			{
				cin >> p[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			c[i].resize(m);
			for (int j = 0; j < m; j++)
			{
				cin >> c[i][j];
			}
		}
		cout << dp(0, -1, p, c, n, m) << "\n";
	}
}