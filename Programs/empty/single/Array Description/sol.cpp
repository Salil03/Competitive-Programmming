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

int table[100010][110];

lll dp(lll idx, lll parent, lll n, lll arr[], lll m)
{
	if (idx == n - 1)
	{
		if (arr[idx] == 0)
		{
			int ans = 0;
			if (parent + 1 <= m)
			{
				ans++;
			}
			if (parent - 1 >= 1)
			{
				ans++;
			}
			if (parent <= m && parent >= 1)
			{
				ans++;
			}
			return ans;
		}
		else
		{
			if (abs(arr[idx] - parent) <= 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	if (arr[idx] != 0)
	{
		if (abs(arr[idx] - parent) <= 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (table[idx][parent] != -1)
	{
		return table[idx][parent];
	}
	lll ans = 0;
	if (parent + 1 <= m)
	{
		ans += dp(idx + 1, parent + 1, n, arr, m) % MOD;
	}
	if (parent - 1 >= 1)
	{
		ans += dp(idx + 1, parent - 1, n, arr, m) % MOD;
	}
	if (parent <= m && parent >= 1)
	{
		ans += dp(idx + 1, parent, n, arr, m) % MOD;
	}
	return table[idx][parent] = (ans % MOD);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n, m;
	cin >> n >> m;
	lll arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	memset(table, -1, sizeof table);
	lll maximum = 0;
	int temp = -1;
	if (arr[0] == 0)
	{
		for (int index = 2; index <= m - 1; index++)
		{
			maximum += dp(0, index, n, arr, m) % MOD;
		}
		for (int index = 0; index < n; index++)
		{
			if (arr[index] != 0)
			{
				temp = index;
				break;
			}
		}
	}
	else
	{
		maximum = 1;
		temp = 0;
	}
	if (temp == -1)
	{
		cout << maximum;
		return 0;
	}
	for (int i = temp; i < n; i++)
	{
		if (arr[i] == 0)
		{
			maximum *= dp(i, arr[i - 1], n, arr, m) % MOD;
			bool flag = true;
			for (int j = i + 1; j < n; j++)
			{
				if (arr[j] != 0)
				{
					i = j;
					flag = false;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
	}
	cout << maximum % MOD;
}