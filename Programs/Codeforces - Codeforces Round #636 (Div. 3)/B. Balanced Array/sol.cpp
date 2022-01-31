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
		lll n;
		cin >> n;
		if (((n / 2) % 2) != 0)
		{
			cout << "NO"
				 << "\n";
		}
		else
		{
			cout << "YES"
				 << "\n";
			int a[n + 1] = {0};
			int first = 2;
			for (int j = 1; j <= (n / 2); j++)
			{
				a[j] = first;
				first = first + 2;
			}
			int alternate = 1;
			for (int j = ((n / 2) + 1); j < n; j++)
			{
				a[j] = a[j - (n / 2)] - alternate;
			}
			a[n] = a[(n / 2)] + (n / 2) - 1;
			for (int j = 1; j < n + 1; j++)
			{
				cout << a[j] << " ";
			}
			cout << "\n";
		}
	}
}