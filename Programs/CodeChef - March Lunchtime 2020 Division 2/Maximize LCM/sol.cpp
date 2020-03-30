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

/*+

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
	while (t--)
	{
		lll n, m;
		cin >> n >> m;
		lll arr[n];
		for (lll i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		lll lcm = arr[0];
		for (lll i = 1; i < n; i++)
		{
			lcm = lcm * arr[i] / __gcd(lcm, arr[i]);
		}
		lll maximum = -1, idx = 1;
		for (lll i = 1; i <= m; i++)
		{
			if (maximum < lcm * i / __gcd(lcm, i))
			{
				maximum = lcm * i / __gcd(lcm, i);
				idx = i;
			}
		}
		cout << idx << "\n";
	}
}