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

void dfs(int node, int visited[], vector<int> graph[])
{
	if (visited[node] > 0)
	{
		return;
	}
	for (auto u : graph[node])
	{
		dfs(u, visited, graph);
	}
}

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
		graph[y].push_back(x);
	}
	pair<int, int> arr[n + 1];
	for (int i = 0; i <= n; i++)
	{
		arr[i].first = graph[i].size();
		arr[i].second = i;
	}
	sort(arr, arr + n + 1);
	int visited[n + 1] = {};
	for (int i = 1; i <= n; i++)
	{
		visited[i] = graph[i].size();
	}
	for (int i = n; i > 0; i--)
	{
		if (visited[arr[i].second] > 1)
		{
			dfs(arr[i].second, visited, graph);
			visited[arr[i].second]--;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] < 1)
		{
			ans++;
		}
	}
	cout << ans;
}