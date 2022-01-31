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
int rem[12], req[12], cost[12], money[12];
int n, m, c0, d0;
int recur(int dough, int idx, int remaining[])
{
	cout << dough << " " << idx << "\n";
	if (idx == -1)
	{
		if (dough < c0)
		{
			return 0;
		}
		int maximum = -1;
		for (int i = -1; i < m; i++)
		{
			maximum = max(maximum, d0 + recur(dough - c0, i, remaining));
			if (i != -1)
			{
				maximum = max(maximum, recur(dough, i, remaining));
			}
		}
		return maximum;
	}
	if (remaining[idx] < req[idx] || dough < cost[idx])
	{
		return 0;
	}
	else
	{
		int maximum = -1;
		for (int i = -1; i < m; i++)
		{
			if (i != idx)
			{
				maximum = max(maximum, recur(dough, i, remaining));
			}
			remaining[idx] -= req[idx];
			maximum = max(maximum, money[idx] + recur(dough - cost[idx], i, remaining));
			remaining[idx] += req[idx];
		}
		return maximum;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> c0 >> d0;
	for (int i = 0; i < m; i++)
	{
		cin >> rem[i] >> req[i] >> cost[i] >> money[i];
	}
	int maximum = 0;
	for (int i = -1; i < m; i++)
	{
		maximum = max(maximum, recur(n, i, rem));
	}
	cout << maximum;
}