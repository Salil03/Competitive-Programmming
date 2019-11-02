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
	int t;
	cin >> t;
	while (t--)
	{
		long long int n;
		int power10 = 0, power2 = 0;
		cin >> n;
		while (n > 1)
		{
			if (n % 10 == 0)
			{
				n /= 10;
				power10++;
			}
			else if (n % 2 == 0)
			{
				n /= 2;
				power2++;
			}
			else
			{
				break;
			}
		}
		if (n == 1 && power2 <= power10)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}