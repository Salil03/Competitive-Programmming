//OPTIMIZATIONS
//#pragma GCC optimize("O3")
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
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> graph[n + 1];
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int s, t;
	cin >> s >> t;
	bool visited[n + 1] = {0};
	visited[s] = true;
	int distance[n + 1] = {0};
	for (int i = 0; i <= n; i++)
	{
		distance[i] = -1;
	}
	distance[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (auto x : graph[temp])
		{
			if (visited[x])
			{
				continue;
			}
			visited[x] = true;
			q.push(x);
			distance[x] = distance[temp] + 1;
		}
	}
	if (distance[t] == -1)
	{
		cout << 0;
	}
	else
	{
		cout << distance[t];
	}
}