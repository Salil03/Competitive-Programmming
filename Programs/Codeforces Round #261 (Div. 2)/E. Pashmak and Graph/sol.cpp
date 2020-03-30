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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> graph[n + 1];
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
	}
	int dp[n + 1] = {0};
	for (int i = 0; i <= n; i++)
	{
		dp[i] = 1;
	}
	queue<pair<int, int>> q;
	q.push({1, -10});
	while (!q.empty())
	{
		int a = q.front().first;
		int w = q.front().second;
		q.pop();
		for (auto u : graph[a])
		{
			if (u.second > w)
			{
				dp[u.first] = max(dp[u.first], dp[a] + 1);
				q.push({u.first, u.second});
			}
		}
	}
	cout << *max_element(dp + 1, dp + n + 1) - 1;
}