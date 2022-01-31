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
lll arr[20][20];
lll table[16][1 << 16];
lll dp(lll mask, lll idx)
{
	if (idx == n)
	{
		return 0;
	}
	if (table[idx][mask] != -1)
	{
		return table[idx][mask];
	}
	lll charge = 0;
	for (lll i = 0; i < n; i++)
	{
		if (i == idx || (mask & (1 << i)))
		{
			charge += arr[idx][i];
		}
	}
	lll minimum = INT_MAX;
	bool flag = false;
	for (lll i = 0; i < n; i++)
	{
		if (i != idx && !(mask & (1 << i)))
		{
			minimum = min(minimum, charge + dp(mask | (1 << idx), i));
			flag = true;
		}
	}
	if (!flag)
	{
		return table[idx][mask] = charge;
	}
	else
	{
		return table[idx][mask] = minimum;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll t;
	cin >> t;
	for (lll test = 1; test <= t; test++)
	{
		cin >> n;
		for (lll i = 0; i < n; i++)
		{
			for (lll j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (lll i = 0; i < n; i++)
		{
			for (lll j = 0; j <= 1 << n; j++)
			{
				table[i][j] = -1;
			}
		}
		lll minimum = INT_MAX;
		for (lll i = 0; i < n; i++)
		{
			minimum = min(minimum, dp(0, i));
		}
		cout << "Case " << test << ": " << minimum << "\n";
	}
}