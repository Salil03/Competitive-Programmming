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
int num, n, k;
int table[104][104][2];
int dp(int idx, bool last, int adj)
{
	if (idx == n)
	{
		if (adj == k)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (table[idx][adj][last] != -1)
	{
		return table[idx][adj][last];
	}
	if (last)
	{
		return table[idx][adj][last] = dp(idx + 1, 1, adj + 1) + dp(idx + 1, 0, adj);
	}
	else
	{
		return table[idx][adj][last] = dp(idx + 1, 1, adj) + dp(idx + 1, 0, adj);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 104; i++)
		{
			for (int j = 0; j < 104; j++)
			{
				table[i][j][0] = -1;
				table[i][j][1] = -1;
			}
		}
		cin >> num >> n >> k;
		cout << num << " " << dp(1, 0, 0) + dp(1, 1, 0) << "\n";
	}
}