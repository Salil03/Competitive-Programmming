//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

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
	int n;
	cin >> n;
	int f[n + 1] = {0};
	int g[n + 1] = {0};
	f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	g[0] = 0;
	g[1] = 1;
	g[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		f[i] = (f[i - 1] % 10000 + f[i - 2] % 10000 + (2 * g[i - 2]) % 10000) % 10000;
		g[i] = (f[i - 1] % 10000 + g[i - 1] % 10000) % 10000;
	}
	cout << f[n] % 10000;
}