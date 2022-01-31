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
		int n;
		cin >> n;
		unordered_map<string, int> names;
		vector<pair<int, int>> graph[n + 1];
		for (int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			names[s] = i;
			int neighbour;
			cin >> neighbour;
			while (neighbour--)
			{
				int x, w;
				cin >> x >> w;
				graph[i].push_back({x, w});
			}
		}
		int r;
		cin >> r;
		while (r--)
		{
			string a, b;
			cin >> a >> b;
			int node1 = names[a], node2 = names[b];
			bool visited[n + 1] = {0};
			int distance[n + 1] = {0};
			for (int i = 1; i <= n; i++)
			{
				distance[i] = INF;
			}
			distance[node1] = 0;
			priority_queue<pair<int, int>> q;
			q.push({0, node1});
			while (!q.empty())
			{
				int curr = q.top().second;
				q.pop();
				if (visited[curr])
				{
					continue;
				}
				visited[curr] = 1;
				bool flag = false;
				for (auto u : graph[curr])
				{
					if (distance[u.first] > distance[curr] + u.second)
					{
						distance[u.first] = distance[curr] + u.second;
						q.push({-distance[u.first], u.first});
					}
				}
			}
			cout << distance[node2] << "\n";
		}
	}
}