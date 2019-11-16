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
	int arr[n + 1] = {0};
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	vector<int> graph[n + 1];
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] != -1)
		{
			graph[i].push_back(arr[i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == -1)
		{
			continue;
		}
		bool visited[n + 1] = {0};
		queue<int> q;
		q.push(i);
		visited[i] = 1;
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
				for (auto v : graph[u])
				{
					graph[s].push_back(v);
				}
			}
		}
	}
	vector<int> final;
	bool visited[n + 1] = {0};
}