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

lll dp(lll maximum, lll minimum, lll node, vector<lll> graph[], lll arr[], lll parent, lll table[])
{
	if (table[node] != INT_MIN)
	{
		return table[node];
	}
	lll ans = maximum - minimum;
	for (auto u : graph[node])
	{
		if (u == parent)
		{
			continue;
		}
		if (maximum < arr[u])
		{
			ans = dp(arr[u], arr[u], u, graph, arr, node, table);
		}
		ans = dp(maximum, min(minimum, arr[u]), u, graph, arr, node, table);
	}
	table[node] = ans;
	return table[node];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n;
	cin >> n;
	vector<lll> graph[n + 1];
	lll arr[n + 1];
	for (lll i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	lll root = 1;
	for (lll i = 1; i <= n; i++)
	{
		lll x;
		cin >> x;
		if (x == -1)
		{
			root = i;
			continue;
		}
		graph[x].push_back(i);
	}
	lll table[n + 1] = {0};
	for (lll i = 1; i <= n; i++)
	{
		table[i] = INT_MIN;
	}
	dp(arr[root], arr[root], root, graph, arr, root, table);
	lll cnt = INT_MIN;
	for (lll i = 1; i <= n; i++)
	{
		cnt = max(cnt, table[i]);
	}
	cout << cnt;
}