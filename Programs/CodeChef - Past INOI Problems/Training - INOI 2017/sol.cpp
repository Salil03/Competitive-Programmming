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

lll cube_sum(lll strength)
{
	lll temp = strength, ans = 0;
	while (temp > 0)
	{
		ans += temp % 10;
		temp /= 10;
	}
	return ans * ans * ans;
}
lll table[5005][5005] = {{0}};
lll dp(lll curr, lll train, lll n, lll e[], lll power[])
{
	if (curr == n)
	{
		return 0;
	}
	if (table[curr][train] != -1)
	{
		return table[curr][train];
	}
	lll ans1 = dp(curr + 1, train + 1, n, e, power);
	lll ans2 = power[train] * e[curr] + dp(curr + 1, train, n, e, power;
	return table[curr][train] = max(ans1, ans2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n, s;
	cin >> n >> s;
	lll e[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> e[i];
	}
	lll power[n + 2];
	power[0] = s;
	for (lll i = 1; i <= n + 1; i++)
	{
		power[i] = power[i - 1] + cube_sum(power[i - 1]);
	}
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			table[i][j] = -1;
		}
	}
	cout << dp(0, 0, n, e, power);
}