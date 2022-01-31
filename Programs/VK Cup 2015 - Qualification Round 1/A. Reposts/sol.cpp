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

int dp(int node, int parent, vector<int> graph[])
{
	int ans = 0;
	for (auto u : graph[node])
	{
		if (u == parent)
		{
			continue;
		}
		ans = max(ans, dp(u, node, graph) + 1);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> graph[210];
	map<string, int> mp;
	int curr = 1;
	while (n--)
	{
		string a, b, c;
		cin >> a >> b >> c;
		transform(a.begin(), a.end(), a.begin(), ::tolower);
		transform(c.begin(), c.end(), c.begin(), ::tolower);
		if (mp.find(c) == mp.end())
		{
			mp[c] = curr;
			curr++;
		}
		if (mp.find(a) == mp.end())
		{
			mp[a] = curr;
			curr++;
		}
		graph[mp[a]].push_back(mp[c]);
		graph[mp[c]].push_back(mp[a]);
	}
	cout << dp(1, -1, graph) + 1;
}