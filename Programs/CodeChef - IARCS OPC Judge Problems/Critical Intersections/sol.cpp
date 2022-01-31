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
bool graph[305][305] = {{0}};
void dfs(int node, bool visited[], int n)
{
	if (visited[node])
	{
		return;
	}
	visited[node] = true;
	for (int j = 1; j <= n; j++)
	{
		if (graph[node][j])
		{
			dfs(j, visited, n);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	int ans = 0;
	vector<int> final;
	for (int i = 1; i <= n; i++)
	{
		bool arr[n + 1] = {0};
		bool flag = false;
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j])
			{
				arr[j] = 1;
				graph[i][j] = 0;
				graph[j][i] = 0;
			}
		}
		bool visited[n + 1] = {0};
		if (i == 1)
		{
			dfs(2, visited, n);
		}
		else
		{
			dfs(1, visited, n);
		}
		for (int k = 1; k <= n; k++)
		{
			if (k == i)
			{
				continue;
			}
			if (!visited[k])
			{
				flag = true;
				break;
			}
		}
		for (int j = 1; j <= n; j++)
		{
			if (arr[j])
			{
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
		if (flag)
		{
			ans++;
			final.push_back(i);
		}
	}
	cout << ans << "\n";
	for (int i : final)
	{
		cout << i << "\n";
	}
}