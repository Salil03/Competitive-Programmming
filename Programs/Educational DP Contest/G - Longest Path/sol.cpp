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
	int n, m;
	cin >> n >> m;
	vector<int> graph[n + 1];
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}
	int distance[n + 1];
	bool visited[n + 1] = {0};
	for (int i = 0; i <= n; i++)
	{
		distance[i] = 0;
	}
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto u : graph[a])
		{
			if (visited[u])
			{
				continue;
			}
			distance[u] = distance[a] + 1;
			visited[u] = true;
			q.push(u);
		}
	}
	int maximum = -1, index = 1;
	for (int i = 1; i <= n; i++)
	{
		if (distance[i] > maximum)
		{
			index = i;
			maximum = distance[i];
		}
	}
	for (int i = 0; i <= n; i++)
	{
		distance[i] = 0;
		visited[i] = 0;
	}
	q.push(index);
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto u : graph[a])
		{
			if (visited[u])
			{
				continue;
			}
			distance[u] = distance[a] + 1;
			visited[u] = true;
			q.push(u);
		}
	}
	cout << *max_element(distance + 1, distance + n + 1);
}