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
lll table[110][110][110][2];
lll dp(lll idx, lll arr[], bool parity, lll rem_od, lll rem_ev) //0even 1odd
{
	if (idx == n)
	{
		return 0;
	}
	if (table[idx][rem_od][rem_ev][parity] != -1)
	{
		return table[idx][rem_od][rem_ev][parity];
	}
	if (arr[idx] != 0)
	{
		if ((arr[idx] & 1) == parity)
		{
			return table[idx][rem_od][rem_ev][parity] = dp(idx + 1, arr, parity, rem_od, rem_ev);
		}
		else
		{
			return table[idx][rem_od][rem_ev][parity] = 1 + dp(idx + 1, arr, arr[idx] & 1, rem_od, rem_ev);
		}
	}
	else
	{
		if (parity)
		{
			lll ans = INT_MAX;
			if (rem_od > 0)
			{
				ans = min(ans, dp(idx + 1, arr, 1, rem_od - 1, rem_ev));
			}
			if (rem_ev > 0)
			{
				ans = min(ans, 1 + dp(idx + 1, arr, 0, rem_od, rem_ev - 1));
			}
			return table[idx][rem_od][rem_ev][parity] = ans;
		}
		else
		{
			lll ans = INT_MAX;
			if (rem_od > 0)
			{
				ans = min(ans, 1 + dp(idx + 1, arr, 1, rem_od - 1, rem_ev));
			}
			if (rem_ev > 0)
			{
				ans = min(ans, dp(idx + 1, arr, 0, rem_od, rem_ev - 1));
			}
			return table[idx][rem_od][rem_ev][parity] = ans;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	lll arr[n];
	bool nums[101] = {};
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i];
		nums[arr[i]] = 1;
	}
	lll odd = 0;
	lll even = 0;
	for (lll i = 1; i <= n; i++)
	{
		if (!nums[i])
		{
			if (i & 1)
			{
				odd++;
			}
			else
			{
				even++;
			}
		}
	}
	for (lll i = 0; i < 110; i++)
	{
		for (lll j = 0; j < 110; j++)
		{
			for (lll k = 0; k < 110; k++)
			{
				table[i][j][k][0] = -1;
				table[i][j][k][1] = -1;
			}
		}
	}
	cout << min(dp(0, arr, 0, odd, even), dp(0, arr, 1, odd, even));
}