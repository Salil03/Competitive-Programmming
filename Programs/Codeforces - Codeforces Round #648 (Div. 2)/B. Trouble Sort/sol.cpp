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
		bool f0 = 0;
		bool f1 = 0;
		bool sorted = 1;
		bool flag = 0;
		lll a[n];
		cin >> a[0];
		for (int j = 1; j < n; j++)
		{
			cin >> a[j];
			if (a[j] < a[j - 1])
			{
				sorted = 0;
			}
		}
		for (int j = 0; j < n; j++)
		{
			int current;
			cin >> current;
			if (current == 0)
			{
				f0 = 1;
			}
			if (current == 1)
			{
				f1 = 1;
			}
		}
		if ((f0 == 1) && (f1 == 1))
		{
			cout << "Yes"
				 << "\n";
		}
		else
		{
			if (sorted == 1)
			{
				cout << "Yes"
					 << "\n";
			}
			else
			{
				cout << "No"
					 << "\n";
			}
		}
	}
}