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
lll table[510][125260];
lll dp(lll idx, lll sum)
{
	if (idx == n + 1)
	{
		if (sum == n * (n + 1) / 4)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (table[idx][sum] != -1)
	{
		return table[idx][sum] % MOD;
	}
	return table[idx][sum] = (dp(idx + 1, sum + idx) + dp(idx + 1, sum)) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if ((n * (n + 1) / 2) & 1)
	{
		cout << 0;
	}
	else
	{
		memset(table, -1, sizeof table);
		cout << (dp(1, 0) / 2) % MOD;
	}
}