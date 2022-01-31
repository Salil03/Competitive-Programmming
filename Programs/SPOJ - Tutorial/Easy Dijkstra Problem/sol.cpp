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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> graph[n + 1];
		while (k--)
		{
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back({b, c});
		}
		int s, g;
		cin >> s >> g;
		priority_queue<pair<int, int>> q;
		int distance[n + 1] = {0};
		for (int i = 1; i <= n; i++)
		{
			distance[i] = INT_MAX;
		}
		distance[s] = 0;
		bool visited[n + 1] = {0};
		q.push({0, s});
		while (!q.empty())
		{
			int node = q.top().second;
			q.pop();
			if (visited[node])
			{
				continue;
			}
			visited[node] = true;
			for (auto u : graph[node])
			{
				int vertex = u.first, weight = u.second;
				if (distance[node] + weight < distance[vertex])
				{
					distance[vertex] = distance[node] + weight;
					q.push({-distance[vertex], vertex});
				}
			}
		}
		if (distance[g] == INT_MAX)
		{
			cout << "NO\n";
		}
		else
		{
			cout << distance[g] << "\n";
		}
	}
}