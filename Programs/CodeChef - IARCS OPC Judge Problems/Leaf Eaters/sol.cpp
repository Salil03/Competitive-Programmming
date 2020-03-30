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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n, k;
	cin >> n >> k;
	lll arr[k];
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}
	int ans = 0;
	for (int b = 0; b < (1 << k); b++)
	{
		int length = __builtin_popcount(b);
		lll lcm = 1;
		bool flag = false;
		for (int i = 0; i < k; i++)
		{
			if (lcm >= n)
			{
				flag = true;
				break;
			}
			if (b & (1 << i))
			{
				lcm *= arr[i] / __gcd(lcm, arr[i]);
			}
		}
		if (flag)
		{
			continue;
		}
		if (length & 1)
		{
			ans -= (n - 1) / lcm;
		}
		else
		{
			ans += (n - 1) / lcm;
		}
	}
	cout << ans;
}