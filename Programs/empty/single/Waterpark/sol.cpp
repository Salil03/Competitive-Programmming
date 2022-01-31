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
int n;
int recur(vector<int> graph[], int node, int table[])
{
	if (node == n)
	{
		return 1;
	}
	if (table[node] != -1)
	{
		return table[node];
	}
	int ans = 0;
	for (auto u : graph[node])
	{
		ans += recur(graph, u, table);
	}
	return table[node] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> graph[n + 1];
	int x, y;
	while (cin >> x)
	{
		cin >> y;
		if (x == 0 && y == 0)
		{
			break;
		}
		graph[x].push_back(y);
	}
	int table[n + 1];
	memset(table, -1, sizeof table);
	cout << recur(graph, 1, table);
}