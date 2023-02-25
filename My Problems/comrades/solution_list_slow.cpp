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
	vector<vector<int>> graph(3 * n + 1, vector<int>());
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 0; i <= 3 * n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	set<int> ans;
	ans.insert(1);
	for (int i = 2; i <= 3 * n; i++)
	{
		bool flag = true;
		for (auto it = ans.begin(); it != ans.end(); it++)
		{
			bool found = false;
			for (auto node : graph[i])
			{
				if (node == *it)
				{
					found = true;
					break;
				}
			}
			if (!found)
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