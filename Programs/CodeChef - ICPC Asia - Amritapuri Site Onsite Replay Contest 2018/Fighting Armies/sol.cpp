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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		uuu c = 1;
		uuu rebel[n];
		for (int i = 0; i < n; i++)
		{
			cin >> rebel[i];
		}
		uuu low, high;
		cin >> low >> high;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (high * __gcd(c, rebel[i]) / rebel[i] < c)
			{
				flag = true;
				break;
			}
			c = c * rebel[i] / __gcd(c, rebel[i]);
		}
		if (flag)
		{
			cout << high - low + 1 << "\n";
			continue;
		}
		uuu first = low + ((c - (low % c)) % c);
		uuu last = high - (high % c);
		cout << high - low + 1 - (((last - first) / c) + 1) << "\n";
	}
}