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

bool dfs(int node, int colour[], vector<int> graph[], bool visited[], int col)
{
	if (visited[node])
	{
		if (colour[node] != col)
		{
			return false;
		}
		return true;
	}
	visited[node] = true;
	colour[node] = col;
	for (auto u : graph[node])
	{
		if (col == 1)
		{
			if (!dfs(u, colour, graph, visited, 2))
			{
				return false;
			}
		}
		if (col == 2)
		{
			if (!dfs(u, colour, graph, visited, 1))
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n, m;
		cin >> n >> m;
		vector<int> graph[n + 1];
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int colour[n + 1] = {0};
		bool visited[n + 1] = {0};
		cout << "Scenario #" << i << ":"
			 << "\n";
		if (!dfs(1, colour, graph, visited, 1))
		{
			cout << "Suspicious bugs found!\n";
		}
		else
		{
			cout << "No suspicious bugs found!\n";
		}
	}
}