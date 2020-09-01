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
	lll n, m;
	cin >> n >> m;
	vector<lll> graph[n + 1];
	for (int i = 0; i < m; i++)
	{
		lll a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	vector<lll> order[n + 1];
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		order[temp].push_back(i + 1);
	}
	bool visited[n + 1] = {0};
	bool flag = true;
	vector<lll> final;
	for (int i = 1; i <= n; i++)
	{
		for (auto node : order[i])
		{
			
		}
	}
}