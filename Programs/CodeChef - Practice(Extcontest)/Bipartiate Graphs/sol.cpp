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

bool dfs(int node, int colour[], bool visited[], vector<int> graph[])
{
	if (visited[node])
	{
		return true;
	}
	visited[node] = true;
	for (auto u : graph[node])
	{
		if (colour[u] == 0)
		{
			if (colour[node] == 2)
			{
				colour[u] = 1;
			}
			else
			{
				colour[u] = 2;
			}
		}
		else if (colour[u] == colour[node])
		{
			return false;
		}
		else if (colour[u] != colour[node])
		{
			dfs(u, colour, visited, graph);
			continue;
		}
		dfs(u, colour, visited, graph);
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
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
	colour[1] = 1;
	bool visited[n + 1] = {0};
	if (dfs(1, colour, visited, graph))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}