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
	lll t;
	cin >> t;
	while (t--)
	{
		lll n, k;
		cin >> n >> k;
		lll arr[n];
		for (lll i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		pair<lll, lll> dp[n];
		for (lll i = 0; i < n; i++)
		{
			dp[i].first = 0;
			dp[i].second = 0;
			for (lll j = i - 1; j >= 0; j--)
			{
				if (arr[j] < arr[i])
				{
					dp[i].first++;
				}
			}
			for (lll j = i + 1; j < n; j++)
			{
				if (arr[j] < arr[i])
				{
					dp[i].second++;
				}
			}
		}
		lll ans = 0;
		for (lll i = 0; i < n; i++)
		{
			ans += dp[i].second * k * (k + 1) / 2;
			ans += dp[i].first * k * (k - 1) / 2;
		}
		cout << ans << "\n";
	}
}