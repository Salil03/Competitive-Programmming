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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> graph[n + 1];
	int in[n + 1] = {};
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		in[y]++;
	}
	int cnt = 0;
	multiset<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
		{
			q.insert(i);
		}
	}
	vector<int> final;
	while (!q.empty())
	{
		int a = *q.begin();
		q.erase(q.begin());
		final.push_back(a);
		cnt++;
		for (auto u : graph[a])
		{
			in[u]--;
			if (in[u] == 0)
			{
				q.insert(u);
			}
		}
	}
	if (cnt != n)
	{
		cout << "Sandro fails.";
	}
	else
	{
		for (int i : final)
		{
			cout << i << " ";
		}
	}
}