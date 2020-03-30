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
	int m, a, b;
	cin >> m >> a >> b;
	vector<pair<int, int>> graph[2001];
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({z, y});
		graph[z].push_back({x, y});
	}
	lll distance[2001] = {};
	for (int i = 0; i <= 2000; i++)
	{
		distance[i] = INT_MAX;
	}
	bool visited[2001] = {0};
	distance[a] = 0;
	priority_queue<pair<lll, lll>> q;
	q.push({0, a});
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
			int curr = u.first, weight = u.second;
			if (distance[node] + weight < distance[curr])
			{
				distance[curr] = distance[node] + weight;
				q.push({-distance[curr], curr});
			}
		}
	}
	if (distance[b] == INT_MAX)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n"
			 << distance[b];
	}
}