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
	lll n, k, q;
	cin >> n >> k >> q;
	lll arr[n][4];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}
	while (q--)
	{
		lll l, y;
		cin >> l >> y;
		lll incon[k] = {};
		for (lll i = 0; i < k; i++)
		{
			incon[i] = INT_MAX;
		}
		for (lll i = 0; i < n; i++)
		{
			if (arr[i][2] <= y && arr[i][3] >= y)
			{
				incon[arr[i][1] - 1] = min(incon[arr[i][1] - 1], abs(arr[i][0] - l));
			}
		}
		lll maximum = -1;
		for (lll i = 0; i < k; i++)
		{
			maximum = max(maximum, incon[i]);
			if (incon[i] == INT_MAX)
			{
				maximum = -1;
				break;
			}
		}
		cout << maximum << "\n";
	}
}