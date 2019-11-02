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

unsigned long long int setleftmostunsetbit(unsigned long long int n)
{
	// if number contain all
	// 1 then return n
	if ((n & (n + 1)) == 0)
		return n;

	// Find position of leftmost unset bit.
	unsigned long long int pos = 0;
	for (unsigned long long int temp = n, count = 0; temp > 0;
		 temp >>= 1, count++)

		// if temp L.S.B is zero
		// then unset bit pos is
		// change
		if ((temp & 1) == 0)
			pos = count;

	// return OR of number and
	// unset bit pos
	return (n | (1 << (pos)));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		unsigned long long int l, right;
		cin >> l >> right;
		long long int r = right;
		unsigned long long int comple = 0;
		while (comple < l || comple < right)
		{
			if (((r + 1) & r) == 0)
			{
				cout << r;
				break;
			}
			unsigned long long int r_set = setleftmostunsetbit(r);
			if (r_set ^ r <= right)
			{
				comple = r_set ^ r;
			}
			else
			{
				break;
			}

			watch(comple);
			watch(r_set);
			r = r_set;
		}
		watch(comple);
	}
}