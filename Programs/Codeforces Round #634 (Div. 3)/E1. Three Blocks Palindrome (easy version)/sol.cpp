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
	int t;
	cin >> t;
	while (t--)
	{
		lll n;
		cin >> n;
		lll arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			arr[i]--;
		}
		if (n < 3)
		{
			cout << 1 << "\n";
			continue;
		}
		lll cnt[n][26];
		memset(cnt, 0, sizeof cnt);
		cnt[0][arr[0]] = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				cnt[i][j] = cnt[i - 1][j];
			}
			cnt[i][arr[i]]++;
		}
		lll dp[n] = {0};
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				dp[i] = 1;
				continue;
			}
			dp[i] = max(dp[i], cnt[i][arr[i]]);
			for (int j = 0; j <= i; j++)
			{
				for (int k = 0; k <= 26; k++)
				{
					dp[i] = max(dp[i], cnt[i][arr[i]] - cnt[j][arr[i]] + 2 * min(cnt[j][k], cnt[n - 1][k] - cnt[i][k]));
				}
			}
		}
		cout << *max_element(dp, dp + n) << "\n";
	}
}