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

int dfs(int node, vector<int> graph[], bool visited[], int mueseum[])
{
	if (visited[node])
	{
		return 0;
	}
	visited[node] = 1;
	int ans = mueseum[node];
	for (auto u : graph[node])
	{
		ans += dfs(u, graph, visited, mueseum);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> graph[n + 1];
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int mueseum[n + 1] = {0};
		for (int i = 1; i <= n; i++)
		{
			cin >> mueseum[i];
		}
		bool visited[n + 1] = {0};
		vector<int> final;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				final.push_back(dfs(i, graph, visited, mueseum));
			}
		}
		sort(final.begin(), final.end());
		if (final.size() < k)
		{
			cout << -1 << "\n";
			continue;
		}
		int minimum = 0, maximum = final.size() - 1, ans = 0;
		for (int i = 0; i < k; i++)
		{
			if (i & 1)
			{
				ans += final[minimum];
				minimum++;
			}
			else
			{
				ans += final[maximum];
				maximum--;
			}
		}
		cout << ans << "\n";
	}
}