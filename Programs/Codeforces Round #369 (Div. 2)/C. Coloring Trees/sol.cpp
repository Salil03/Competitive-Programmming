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
lll p[110][110];
lll table[110][110][110];
lll n, m, k;
lll dp(lll idx, lll blocks, lll arr[], lll last)
{
	if (idx == n)
	{
		if (blocks != k)
		{
			return INF;
		}
		else
		{
			return 0;
		}
	}
	if (table[idx][blocks][last] != -1)
	{
		return table[idx][blocks][last];
	}
	if (arr[idx] != 0)
	{
		if (arr[idx] != last)
		{
			return table[idx][blocks][last] = dp(idx + 1, blocks + 1, arr, arr[idx]);
		}
		else
		{
			return table[idx][blocks][last] = dp(idx + 1, blocks, arr, arr[idx]);
		}
	}
	else
	{
		lll ans = INF;
		for (lll i = 1; i <= m; i++)
		{
			if (last == i)
			{
				ans = min(ans, p[idx][i] + dp(idx + 1, blocks, arr, i));
			}
			else
			{
				ans = min(ans, p[idx][i] + dp(idx + 1, blocks + 1, arr, i));
			}
		}
		return table[idx][blocks][last] = ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	lll arr[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (lll i = 0; i < n; i++)
	{
		for (lll j = 1; j <= m; j++)
		{
			cin >> p[i][j];
		}
	}
	for (int i = 0; i < 110; i++)
	{
		for (int j = 0; j < 110; j++)
		{
			for (int f = 0; f < 110; f++)
			{
				table[i][j][f] = -1;
			}
		}
	}
	if (dp(0, 0, arr, 105) >= INF)
	{
		cout << -1;
	}
	else
	{
		cout << dp(0, 0, arr, 105);
	}
}