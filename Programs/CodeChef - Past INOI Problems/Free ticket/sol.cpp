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
	lll c,f;
	cin >> c >> f;
	vector<pair<lll, lll>> graph[c+1];
	while(f--)
	{
		lll x,y,p;
		cin >> x >> y >> p;
		graph[x].push_back({y,p});
		graph[y].push_back({x,p});
	}
	lll distance[c+1][c+1] = {};
	for(int i = 0; i<=c; i++)
	{
		for(int j = 0; j<=c; j++)
		{
			distance[i][j] = INF;
		}
	}
	for(int i = 1;i<=c; i++)
	{
		priority_queue<pair<lll, lll>> q;
		distance[i][i] = 0;
		bool visited[c+1] = {};
		q.push({0, i});
		while(!q.empty())
		{
			int a = q.top().second;
			q.pop();
			visited[a] = 1;
			for(auto u : graph[a])
			{
				if(visited[u.first])
				{
					continue;
				}
				int w = u.second, b = u.first;
				if(distance[i][b] > distance[i][a] + w)
				{
					distance[i][b] = distance[i][a] +w;
					q.push({-distance[i][b], b});
				}
			}
		}
	}
	lll maximum = -1;
	for(int i = 1; i<=c; i++)
	{
		for(int j = 1; j<=c; j++)
		{
			maximum = max(maximum, distance[i][j]);
		}
	}
	cout << maximum;
}