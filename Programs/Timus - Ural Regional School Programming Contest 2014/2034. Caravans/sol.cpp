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

int recur(int node, vector<int> parent[], int distance[], int prev, int source, bool visited[])
{
	if (visited[node])
	{
		return 0;
	}
	visited[node] = 1;
	int minimum = distance[node];
	int ans = -1;
	if (node == source)
	{
		return minimum;
	}
	for (auto u : parent[node])
	{
		if (u != prev)
		{
			minimum = min(minimum, recur(u, parent, distance, node, source, visited));
			ans = max(ans, minimum);
		}
	}
	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> graph[n + 1];
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int s, f, r;
	cin >> s >> f >> r;
	vector<int> parent[n + 1];
	int distance[n + 1] = {};
	for (int i = 0; i <= n; i++)
	{
		distance[i] = INT_MAX;
	}
	distance[r] = 0;
	queue<int> q;
	q.push(r);
	bool visited[n + 1] = {};
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		visited[node] = 1;
		for (auto u : graph[node])
		{
			if (!visited[u] && distance[u] >= distance[node] + 1)
			{
				parent[u].push_back(node);
				parent[node].push_back(u);
				distance[u] = distance[node] + 1;
				q.push(u);
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		visited[i] = 0;
	}
	cout << recur(f, parent, distance, -1, s, visited);
}