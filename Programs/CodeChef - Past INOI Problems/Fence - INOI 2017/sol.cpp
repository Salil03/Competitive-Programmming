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
map<pair<int, int>, bool> graph;
map<pair<int, int>, bool> visited;

int dfs(int row, int col)
{
	if (visited[{row, col}])
	{
		return 0;
	}
	visited[{row, col}] = 1;
	int cnt = 4;
	if (graph.find({row + 1, col}) != graph.end())
	{
		cnt--;
		cnt += dfs(row + 1, col);
	}
	if (graph.find({row, col + 1}) != graph.end())
	{
		cnt--;
		cnt += dfs(row, col + 1);
	}
	if (graph.find({row - 1, col}) != graph.end())
	{
		cnt--;
		cnt += dfs(row - 1, col);
	}
	if (graph.find({row, col - 1}) != graph.end())
	{
		cnt--;
		cnt += dfs(row, col - 1);
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int r, c, n;
	cin >> r >> c >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		graph[{x, y}] = 1;
	}
	int maximum = 1;
	for (auto i : graph)
	{
		visited[i.first] = 0;
	}
	for (auto i : graph)
	{
		if (!visited[i.first])
		{
			maximum = max(maximum, dfs(i.first.first, i.first.second));
		}
	}
	cout << maximum;
}