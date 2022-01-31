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
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	lll n;
	cin >> n;
	pair<lll, lll> arr[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	lll maximum = 0;
	for (lll i = 0; i < n; i++)
	{
		lll x_max = 0, y_max = 0;
		for (lll j = 0; j < n; j++)
		{
			if (arr[j].first == arr[i].first)
			{
				y_max = max(y_max, abs(arr[j].second - arr[i].second));
			}
			if (arr[j].second == arr[i].second)
			{
				x_max = max(x_max, abs(arr[j].first - arr[i].first));
			}
		}
		maximum = max(maximum, x_max * y_max);
	}
	cout << maximum;
}