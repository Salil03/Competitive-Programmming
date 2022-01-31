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

int dfs(int source, vector<int> graph[], bool visited[])
{
	if (visited[source])
	{
		return 0;
	}
	visited[source] = true;
	int ans = 1;
	for (auto u : graph[source])
	{
		ans += dfs(u, graph, visited);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	vector<int> graph[n + 1];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] - arr[i] >= k)
			{
				graph[j + 1].push_back(i + 1);
				graph[i + 1].push_back(j + 1);
			}
		}
	}
	bool visited[n + 1] = {0};
	int maximum = -1;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			maximum = max(maximum, dfs(i, graph, visited));
		}
	}
	cout << maximum;
}