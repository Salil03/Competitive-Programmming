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
int n;
int arr[20][20];
int table[17][1 << 17];
int dp(int man, int mask)
{
	if (man == n)
	{
		return 0;
	}
	if (table[man][mask] != -1)
	{
		return table[man][mask];
	}
	int maximum = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(mask & (1 << i)))
		{
			maximum = max(maximum, arr[man][i] + dp(man + 1, mask | (1 << i)));
		}
	}
	return table[man][mask] = maximum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= 1 << n; j++)
			{
				table[i][j] = -1;
			}
		}
		cout << "Case " << k << ": " << dp(0, 0) << "\n";
	}
}