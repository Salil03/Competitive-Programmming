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

int dfs(int node, bool visited[], vector<int> graph[])
{
	if(visited[node])
	{
		return 0;
	}
	visited[node] = 1;
	int ans = 1;
	for(auto u : graph[node])
	{
		ans += dfs(u, visited, graph);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	vector<int> id[n];
	for(int i = 0; i<n; i++)
	{
		int p;
		cin >> p;
		id[i].resize(p);
		for(int j = 0; j<p; j++)
		{
			cin >> id[i][j];
		}
		sort(id[i].begin(), id[i].end());
	}
	vector<int> graph[n];
	for(int i = 0; i<n-1; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			int cnt = 0;
			for(int num : id[j])
			{
				if(binary_search(id[i].begin(), id[i].end(), num))
				{
					cnt++;
				}
			}
			if(cnt >=k)
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	bool visited[n] = {};
	cout << dfs(0, visited, graph);
}