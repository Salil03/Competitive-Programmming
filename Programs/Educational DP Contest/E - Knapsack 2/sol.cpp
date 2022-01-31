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
map<pair<ll, ll>, ll> table;
ll dp(ll curr, pair<ll, ll> arr[], ll n, ll rem)
{
	if (curr >= n)
	{
		return 0;
	}
	if (rem <= 0)
	{
		return 0;
	}
	if (table.find({curr, rem}) != table.end())
	{
		return table[{curr, rem}];
	}
	if (arr[curr].first > rem)
	{
		return table[{curr, rem}] = dp(curr + 1, arr, n, rem);
	}
	return table[{curr, rem}] = max(dp(curr + 1, arr, n, rem), arr[curr].second + dp(curr + 1, arr, n, rem - arr[curr].first));
}

int main()
{
	ll n, w;
	cin >> n >> w;
	pair<ll, ll> arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	cout << dp(0, arr, n, w);
}