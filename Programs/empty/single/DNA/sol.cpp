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
prashsal

URL: url

Solution Begins here
*/
int dp[1010][1010];

int recurse_dp(string s, int i, int j)
{
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	if ((j - i) <= 4)
	{
		return 0;
	}
	int a = recurse_dp(s, i, j - 1);
	int maximum = 0;
	for (int t = i; t <= j - 5; t++)
	{
		int set = 0;
		if ((s[j - 1] == 'A') && (s[t - 1] == 'U'))
		{
			set = 1;
		}
		if ((s[j - 1] == 'U') && (s[t - 1] == 'A'))
		{
			set = 1;
		}
		if ((s[j - 1] == 'G') && (s[t - 1] == 'C'))
		{
			set = 1;
		}
		if ((s[j - 1] == 'C') && (s[t - 1] == 'G'))
		{
			set = 1;
		}
		if (set != 1)
		{
			continue;
		}
		if ((recurse_dp(s, i, t - 1) + recurse_dp(s, t + 1, j - 1) + 1) > maximum)
		{
			maximum = recurse_dp(s, i, t - 1) + recurse_dp(s, t + 1, j - 1) + 1;
		}
	}
	int ret = max(a, maximum);
	dp[i][j] = ret;
	return ret;
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
		string s;
		cin >> s;
		int n = s.length();
		for (int i = 0; i < 1010; i++)
		{
			for (int j = 0; j < 1010; j++)
			{
				if ((j - i) <= 4)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = -1;
				}
			}
		}
		cout << recurse_dp(s, 1, n) << "\n";
	}
}