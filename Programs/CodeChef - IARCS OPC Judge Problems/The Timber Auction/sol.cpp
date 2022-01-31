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
	lll m, n;
	cin >> m >> n;
	lll arr[m][n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	lll prefix[m][n] = {};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > 0)
			{
				prefix[i][j] += prefix[i - 1][j];
			}
			if (j > 0)
			{
				prefix[i][j] += prefix[i][j - 1];
			}
			if (i > 0 && j > 0)
			{
				prefix[i][j] -= prefix[i - 1][j - 1];
			}
			prefix[i][j] += arr[i][j];
		}
	}
	lll c;
	cin >> c;
	while (c--)
	{
		lll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		x2--;
		y1--;
		y2--;
		lll ans = 0;
		ans += prefix[x2][y2];
		if (x1 > 0)
		{
			ans -= prefix[x1 - 1][y2];
		}
		if (y1 > 0)
		{
			ans -= prefix[x2][y1 - 1];
		}
		if (x1 > 0 && y1 > 0)
		{
			ans += prefix[x1 - 1][y1 - 1];
		}
		cout << ans << "\n";
	}
}