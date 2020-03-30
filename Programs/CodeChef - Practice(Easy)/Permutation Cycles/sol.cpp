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
vector<int> ans;
void dfs(int node, bool visited[], int arr[])
{
	if (visited[node])
	{
		return;
	}
	visited[node] = 1;
	ans.push_back(node + 1);
	dfs(arr[node] - 1, visited, arr);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	bool visited[n] = {};
	vector<vector<int>> final;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			ans.clear();
			dfs(i, visited, arr);
			ans.push_back(i + 1);
			final.push_back(ans);
		}
	}
	cout << final.size() << "\n";
	for (auto u : final)
	{
		for (int i : u)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
}