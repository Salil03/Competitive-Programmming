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

lll recur(tuple<lll, lll, lll> arr[], lll idx, lll dp[])
{
	if (idx == 0)
	{
		return get<2>(arr[0]);
	}
	if (dp[idx] != -1)
	{
		return dp[idx];
	}
	lll ans = recur(arr, idx - 1, dp);
	lll temp = get<2>(arr[idx]);
	for (lll i = idx - 1; i >= 0; i--)
	{
		if (get<0>(arr[i]) <= get<1>(arr[idx]))
		{
			temp += recur(arr, i, dp);
			break;
		}
	}
	ans = max(ans, temp);
	return dp[idx] = ans;
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
		lll n;
		cin >> n;
		tuple<lll, lll, lll> arr[n];
		for (lll i = 0; i < n; i++)
		{
			lll x, y, z;
			cin >> x >> y >> z;
			y += x;
			arr[i] = make_tuple(y, x, z);
		}
		lll dp[n];
		memset(dp, -1, sizeof dp);
		sort(arr, arr + n);
		cout << recur(arr, n - 1, dp) << "\n";
	}
}