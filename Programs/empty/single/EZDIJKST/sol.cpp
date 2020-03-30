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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll t;
	cin >> t;
	while (t--)
	{
		lll n, m;
		cin >> n >> m;
		vector<pair<lll, lll>> graph[n + 1];
		while (m--)
		{
			lll x, y, z;
			cin >> x >> y >> z;
			graph[x].push_back({y, z});
		}
		lll source, target;
		cin >> source >> target;
		lll distance[n + 1] = {};
		for (int i = 0; i <= n; i++)
		{
			distance[i] = INT_MAX;
		}
		distance[source] = 0;
		bool visited[n + 1] = {};
		queue<pair<lll, lll>> q;
		q.push({0, source});
		while (!q.empty())
		{
			lll a = q.front().second;
			q.pop();
			visited[a] = true;
			for (auto u : graph[a])
			{
				lll b = u.first, w = u.second;
				if (visited[b])
				{
					continue;
				}
				if (distance[b] > distance[a] + w)
				{
					distance[b] = distance[a] + w;
					q.push({-distance[b], b});
				}
			}
		}
		if (distance[target] == INT_MAX)
		{
			cout << "NO\n";
		}
		else
		{
			cout << distance[target] << "\n";
		}
	}
}