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

bool cycle(int node, vector<int> graph[], bool visited[], int parent)
{
	visited[node] = true;
	for (auto u : graph[node])
	{
		if (!visited[u])
		{
			if (cycle(u, graph, visited, node))
			{
				return true;
			}
		}
		else if (u != parent)
		{
			return true;
		}
	}
	return false;
}

void connected(int node, vector<int> graph[], bool visited[])
{
	if (visited[node])
	{
		return;
	}
	visited[node] = true;
	for (auto u : graph[node])
	{
		connected(u, graph, visited);
	}
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
	bool visited[n + 1] = {0};
	if (cycle(1, graph, visited, 0))
	{
		cout << "NO";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
	connected(1, graph, visited);
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}