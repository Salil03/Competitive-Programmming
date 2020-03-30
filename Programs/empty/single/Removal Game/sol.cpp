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
lll table[5010][5010];
lll dp(lll left, lll right, lll arr[])
{
	if (left == right)
	{
		return arr[left];
	}
	if (table[left][right] != -1)
	{
		return table[left][right];
	}
	return table[left][right] = max(arr[left] - dp(left + 1, right, arr), arr[right] - dp(left, right - 1, arr));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n;
	cin >> n;
	lll arr[n];
	lll sum = 0;
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	memset(table, -1, sizeof table);
	cout << (sum + dp(0, n - 1, arr)) / 2;
}