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
#define INF 1000000000
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
		ll n, que;
		cin >> n >> que;
		map<ll, vector<int>> graph;
		ll u, v;
		for (ll i = 0; i < n - 1; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		while (que--)
		{
			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			for (int i = 1; i <= n; i++)
			{
				map<ll, ll> distance;
				priority_queue<pair<ll, ll>> q;
				map<ll, bool> processed;
				for (int i = 1; i <= n; i++)
					distance[i] = INF;
				distance[a] = 0;
				q.push({0, a});
				while (!q.empty())
				{
					int up = q.top().second;
					q.pop();
					if (processed[up])
						continue;
					processed[a] = true;
					for (auto u : graph[up])
					{
						int down = u.first, w = u.second;
						if (distance[up] + w < distance[down])
						{
							distance[down] = distance[up] + w;
							q.push({-distance[down], down});
						}
					}
				}
				map<ll, ll> distance2;
				priority_queue<pair<ll, ll>> q2;
				map<ll, bool> processed2;
				for (int i = 1; i <= n; i++)
					distance2[i] = INF;
				distance2[a] = 0;
				q2.push({0, a});
				while (!q2.empty())
				{
					int up2 = q.top().second;
					q.pop();
					if (processed[up])
						continue;
					processed[a] = true;
					for (auto u : graph[up])
					{
						int down = u.first, w = u.second;
						if (distance[up] + w < distance[down])
						{
							distance[down] = distance[up] + w;
							q.push({-distance[down], down});
						}
					}
				}
			}
		}
	}
}