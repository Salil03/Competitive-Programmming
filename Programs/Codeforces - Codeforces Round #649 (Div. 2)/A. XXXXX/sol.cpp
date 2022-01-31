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
	lll t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		lll n, x;
		cin >> n >> x;
		lll a[n];
		lll s = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		for (int j = 0; j < n; j++)
		{
			s = s + a[j];
		}
		if ((s % x) != 0)
		{
			cout << n << "\n";
		}
		else
		{
			lll first = -1;
			lll last = -1;
			for (int j = 0; j < n; j++)
			{
				if (a[j] % x != 0)
				{
					first = j;
					break;
				}
			}
			for (int j = n - 1; j >= 0; j--)
			{
				if (a[j] % x != 0)
				{
					last = j;
					break;
				}
			}
			if (first == -1 && last == -1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << max(last, n - first - 1) << "\n";
			}
		}
	}
}