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
const int INF = 0x3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

vector<int> a;

bool isPal(int l, int r)
{
	int s = (r + l) / 2;

	for (int i = l; i <= s; i++)
	{
		if (a[i] != a[r - i + l])
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;

	int x;
	a.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		a.push_back(x);
	}

	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (isPal(j, i))
			{
				// cout << j << " " << i << endl;
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}

	cout << dp[n] << endl;
}