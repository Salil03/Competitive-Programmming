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

lll modular[53] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	modular[0] = 1;
	for (lll i = 1; i < 53; i++)
	{
		modular[i] = 2 * modular[i - 1];
	}
	while (t--)
	{
		lll p, idx;
		cin >> p >> idx;
		string s;
		for (lll i = 0; i < p; i++)
		{
			s += '0';
		}
		for (lll i = 0; i < p; i++)
		{
			if (idx & (1LL << (i)))
			{
				s[i] = '1';
			}
		}
		lll ans = 0;
		for (lll i = p - 1; i >= 0; i--)
		{
			if (s[i] == '1')
			{
				ans += modular[p - 1 - i];
			}
		}
		cout << ans << "\n";
	}
}