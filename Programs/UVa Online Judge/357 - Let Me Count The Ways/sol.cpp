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

lll coins[5] = {1, 5, 10, 25, 50};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n;
	while (cin >> n)
	{
		lll dp[n + 1] = {1};
		for (lll i = 0; i < 5; i++)
		{
			for (lll j = coins[i]; j <= n; j++)
			{
				dp[j] += dp[j - coins[i]];
			}
		}
		if (dp[n] == 1)
		{
			cout << "There is only 1 way to produce " << n << " cents change.";
		}
		else
		{
			cout << "There are " << dp[n] << " ways to produce " << n << " cents change.";
		}
		cout << "\n";
	}
}