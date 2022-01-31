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

int table[510][510];

int dp(int rem, int idx, int w[], int v[], int n)
{
	if (idx == n)
	{
		return 0;
	}
	if (table[rem][idx] != -1)
	{
		return table[rem][idx];
	}
	if (rem < w[idx])
	{
		return table[rem][idx] = dp(rem, idx + 1, w, v, n);
	}
	return table[rem][idx] = max(v[idx] + dp(rem - w[idx], idx + 1, w, v, n), dp(rem, idx + 1, w, v, n));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int w[n], v[n];
	memset(table, -1, sizeof table);
	for (int i = 0; i < n; i++)
	{
		cin >> w[i] >> v[i];
	}
	cout << dp(m, 0, w, v, n);
}