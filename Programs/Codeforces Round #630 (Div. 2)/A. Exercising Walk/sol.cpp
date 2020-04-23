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
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if (x < x1 || x > x2)
		{
			cout << "No\n";
			continue;
		}
		if (y < y1 || y > y2)
		{
			cout << "No\n";
			continue;
		}
		if (x + 1 <= x2 || x - 1 >= x1)
		{
			if (a >= b)
			{
				a -= b;
				b = 0;
				if (x - a < x1 || x - a > x2)
				{
					cout << "No\n";
					continue;
				}
			}
			else
			{
				b -= a;
				a = 0;
				if (x + b < x1 || x + b > x2)
				{
					cout << "No\n";
					continue;
				}
			}
		}
		else
		{
			if (a > 0 || b > 0)
			{
				cout << "No\n";
				continue;
			}
		}
		if (y + 1 <= y2 || y - 1 >= y1)
		{
			if (c >= d)
			{
				c -= d;
				d = 0;
				if (y - c < y1 || y - c > y2)
				{
					cout << "No\n";
					continue;
				}
			}
			else
			{
				d -= c;
				c = 0;
				if (y + d < y1 || y + d > y2)
				{
					cout << "No\n";
					continue;
				}
			}
		}
		else
		{
			if (c > 0 || d > 0)
			{
				cout << "No\n";
				continue;
			}
		}
		cout << "Yes\n";
	}
}