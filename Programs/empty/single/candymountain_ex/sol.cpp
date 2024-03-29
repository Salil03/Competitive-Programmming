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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n, k;
	cin >> n >> k;
	lll arr[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	if (2 * n < 2 * k)
	{
		cout << 0 << "\n";
		return 0;
	}
	lll dp[n] = {};
	memset(dp, INF, sizeof dp);
	for (lll i = 0; i < min(k, n); i++)
	{
		dp[i] = arr[i];
	}
	for (lll i = k; i < n; i++)
	{
		for (lll j = i - 1; j >= max(i - k, 0LL); j--)
		{
			dp[i] = min(dp[i], dp[j]);
		}
		dp[i] = max(dp[i], arr[i]);
	}
	cout << *min_element(dp + max(n - k, 0LL), dp + n);
}