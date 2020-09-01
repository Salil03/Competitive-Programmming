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
bool isPowerOfTwo(lll x)
{
	/* First x in the below expression is for the case when x is 0 */
	return x && (!(x & (x - 1)));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll t;
	cin >> t;
	while (t--)
	{
		lll a, b;
		cin >> a >> b;
		if (a > b)
		{
			if (a % b != 0 || !isPowerOfTwo(a / b))
			{
				cout << -1 << "\n";
				continue;
			}
			lll num = log2(a / b);
			cout << cel(num, 3) << "\n";
		}
		else if (a < b)
		{
			if (b % a != 0 || !isPowerOfTwo(b / a))
			{
				cout << -1 << "\n";
				continue;
			}
			lll num = log2(b / a);
			cout << cel(num, 3) << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}
}