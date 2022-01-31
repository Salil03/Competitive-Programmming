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
	int m, n, s;
	cin >> m >> n >> s;
	pair<int, int> seed[s];
	for (int i = 0; i < s; i++)
	{
		cin >> seed[i].first >> seed[i].second;
		seed[i].first--;
		seed[i].second--;
	}
	lll arr[m][n] = {};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = INT_MAX;
		}
	}
	bool visited[m][n] = {};
	queue<pair<int, int>> q;
	for (int i = 0; i < s; i++)
	{
		arr[seed[i].first][seed[i].second] = 0;
		q.push({seed[i].first, seed[i].second});
	}
	while (!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		if (row > 0)
		{
			if (!visited[row - 1][col])
			{
				visited[row - 1][col] = true;
				arr[row - 1][col] = min(arr[row - 1][col], arr[row][col] + 1);
				q.push({row - 1, col});
			}
		}
		if (col > 0)
		{
			if (!visited[row][col - 1])
			{
				visited[row][col - 1] = true;
				arr[row][col - 1] = min(arr[row][col - 1], arr[row][col] + 1);
				q.push({row, col - 1});
			}
		}
		if (row > 0 && col > 0)
		{
			if (!visited[row - 1][col - 1])
			{
				visited[row - 1][col - 1] = true;
				arr[row - 1][col - 1] = min(arr[row - 1][col - 1], arr[row][col] + 1);
				q.push({row - 1, col - 1});
			}
		}
		if (row < m - 1)
		{
			if (!visited[row + 1][col])
			{
				visited[row + 1][col] = true;
				arr[row + 1][col] = min(arr[row + 1][col], arr[row][col] + 1);
				q.push({row + 1, col});
			}
		}
		if (col < n - 1)
		{
			if (!visited[row][col + 1])
			{
				visited[row][col + 1] = true;
				arr[row][col + 1] = min(arr[row][col + 1], arr[row][col] + 1);
				q.push({row, col + 1});
			}
		}
		if (row < m - 1 && col < n - 1)
		{
			if (!visited[row + 1][col + 1])
			{
				visited[row + 1][col + 1] = true;
				arr[row + 1][col + 1] = min(arr[row + 1][col + 1], arr[row][col] + 1);
				q.push({row + 1, col + 1});
			}
		}
		if (row > 0 && col < n - 1)
		{
			if (!visited[row - 1][col + 1])
			{
				visited[row - 1][col + 1] = true;
				arr[row - 1][col + 1] = min(arr[row - 1][col + 1], arr[row][col] + 1);
				q.push({row - 1, col + 1});
			}
		}
		if (row < m - 1 && col > 0)
		{
			if (!visited[row + 1][col - 1])
			{
				visited[row + 1][col - 1] = true;
				arr[row + 1][col - 1] = min(arr[row + 1][col - 1], arr[row][col] + 1);
				q.push({row + 1, col - 1});
			}
		}
	}
	set<int> final;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			final.insert(arr[i][j]);
		}
	}
	cout << final.size();
}