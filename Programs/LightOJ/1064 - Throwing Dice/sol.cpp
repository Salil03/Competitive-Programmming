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
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		uuu n, x;
		cin >> n >> x;
		uuu arr[n + 2][160] = {{0}};
		for (int i = 0; i <= 150; i++)
		{
			arr[0][i] = 0;
		}
		arr[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			arr[i][0] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 150; j++)
			{
				for (int k = j - 1; k >= j - 6 && k >= 0; k--)
				{
					arr[i][j] += arr[i - 1][k];
				}
			}
		}
		uuu ans = 0;
		for (int i = x; i <= 154; i++)
		{
			ans += arr[n][i];
		}
		uuu gcd = __gcd(ans, (uuu)pow(6, n));
		if (ans == 0)
		{
			cout << "Case " << test << ": " << 0 << "\n";
			continue;
		}
		if (ans == (uuu)pow(6, n))
		{
			cout << "Case " << test << ": " << 1 << "\n";
			continue;
		}
		cout << "Case " << test << ": " << ans / gcd << "/" << (uuu)pow(6, n) / gcd << "\n";
	}
}