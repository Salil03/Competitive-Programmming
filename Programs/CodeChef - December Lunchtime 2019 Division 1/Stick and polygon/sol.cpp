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
int n;
int dp(int side, int sum)
{
	if (side == n)
	{
		if (sum > n)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		lll sum = 0;
		for (int i = 2; i <= n; i++)
		{
			for (int j = i - 1; j > 0; j--)
			{
				sum += dp(i, i + j);
			}
		}
		cout << sum << "\n";
	}
}