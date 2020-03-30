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
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> graph[n + 1];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bool visited[n + 1] = {0};
	int distance[n + 1] = {0};
	visited[1] = true;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		for (auto u : graph[s])
		{
			if (visited[u])
			{
				continue;
			}
			visited[u] = 1;
			q.push(u);
			distance[u] = distance[s] + 1;
		}
	}
	int max1 = max_element(distance, distance + n + 1) - distance;
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 0;
		distance[i] = 0;
	}
	visited[max1] = 1;
	q.push(max1);
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		for (auto u : graph[s])
		{
			if (visited[u])
			{
				continue;
			}
			visited[u] = 1;
			q.push(u);
			distance[u] = distance[s] + 1;
		}
	}
	cout << *max_element(distance, distance + n + 1);
} 