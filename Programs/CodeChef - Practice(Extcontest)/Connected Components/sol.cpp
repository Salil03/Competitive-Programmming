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

/*
$alil03

URL: url

Solution Begins here
*/

void dfs(int node, bool visited[], vector<int> graph[])
{
	if (visited[node])
	{
		return;
	}
	visited[node] = true;
	for (auto u : graph[node])
	{
		dfs(u, visited, graph);
	}
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
		int n, e;
		cin >> n >> e;
		vector<int> graph[n];
		while (e--)
		{
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		bool visited[n] = {0};
		int cnt = 0;
		bool flag = false;
		while (!flag)
		{
			flag = true;
			for (int i = 0; i < n; i++)
			{
				if (!visited[i])
				{
					flag = false;
					cnt++;
					dfs(i, visited, graph);
				}
			}
		}
		cout << cnt << "\n";
	}
}