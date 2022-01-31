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

int main()
{
	lll n;
	cin >> n;
	lll w[n] = {0}, p[n] = {0};
	cout << 1 << " " << 1 << " " << 10000 << "\n";
	fflush(stdout);
	cin >> p[0];
	for (lll i = 1; i < n; i++)
	{
		cout << 1 << " " << i + 1 << " " << 10000 << "\n";
		fflush(stdout);
		cin >> p[i];
	}
	for (lll i = 0; i < n; i++)
	{
		lll high = 1000;
		lll low = 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			cout << 1 << " " << i << " " << mid << endl;
			fflush(stdout);
			int ans;
			cin >> ans;
			if (ans >= p[i])
			{
				high = mid - 1;
				continue;
			}
			else
			{
				low = mid + 1;
				continue;
			}
		}
		w[i] = high + 1;
	}
	for (lll i = n - 1; i > 0; i--)
	{
		w[i] -= w[i - 1];
		p[i] -= p[i - 1];
	}
	cout << 2 << "\n";
	fflush(stdout);
	for (lll i : w)
	{
		cout << i << " ";
	}
	cout << "\n";
	fflush(stdout);
	for (lll i : p)
	{
		cout << i << " ";
	}
	return 0;
}