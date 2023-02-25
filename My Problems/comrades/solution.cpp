#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	n /= 3;
	vector<vector<bool>> graph(3 * n + 1, vector<bool>(3 * n + 1, false));
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u][v] = true;
		graph[v][u] = true;
	}
	set<int> ans;
	ans.insert(1);
	for (int i = 2; i <= 3 * n; i++)
	{
		bool flag = true;
		for (auto it = ans.begin(); it != ans.end(); it++)
		{
			if (!graph[i][*it])
			{
				flag = false;
				ans.erase(it);
				break;
			}
		}
		if (flag)
		{
			ans.insert(i);
		}
	}
	auto it = ans.begin();
	while (it != ans.end() && n--)
	{
		cout << *it << " ";
		it++;
	}
}