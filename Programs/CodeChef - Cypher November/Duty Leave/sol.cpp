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
	lll n;
	lll x, odd = 0, even = 0;
	cin >> n;
	for (lll i = 0; i < n; i++)
	{
		cin >> x;
		if (x & 1)
		{
			odd++;
		}
		else
		{
			even++;
		}
	}
	if (n & 1)
	{
		if (even == (n - 1) / 2 || odd == (n - 1) / 2)
		{
			cout << "DL";
		}
		else
		{
			cout << "DETAIN";
		}
	}
	else
	{
		if (even == n / 2 || odd == n / 2)
		{
			cout << "DL";
		}
		else
		{
			cout << "DETAIN";
		}
	}
}