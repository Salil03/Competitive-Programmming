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
lll n, k, table[1000001][2];
lll dp(lll idx, bool last_1, lll arr1[], lll arr2[])
{
	if (idx == n)
	{
		return 0;
	}
	if (table[idx][last_1] != -1)
	{
		return table[idx][last_1];
	}
	if (last_1)
	{
		return table[idx][last_1] = max(arr1[idx] + dp(idx + 1, last_1, arr1, arr2), arr2[idx] - k + dp(idx + 1, 0, arr1, arr2));
	}
	else
	{
		return table[idx][last_1] = max(arr1[idx] - k + dp(idx + 1, 1, arr1, arr2), arr2[idx] + dp(idx + 1, last_1, arr1, arr2));
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	lll arr1[n], arr2[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}
	for (lll i = 0; i < n; i++)
	{
		cin >> arr2[i];
	}
	memset(table, -1, sizeof table);
	cout << max(arr1[0] + dp(1, 1, arr1, arr2), arr2[0] + dp(1, 0, arr1, arr2));
}