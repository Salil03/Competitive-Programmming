#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,u,v;
	cin >> n >> m;
	vector<int> graph[n+1];
	for(int i = 0; i<m; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cin >> u >> v;
	int d[n+1] = {0};
	d[u] = 0;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		for(int j = 0; j< graph[temp].size(); j++)
		{
			int temp2 = graph[temp][j];
			if(d[temp2] == 0)
			{
				d[temp2] = d[temp] +1;
				q.push(temp2);
			}
		}
	}
	if(d[v] == INT_MAX)
	{
		cout << 0;
	}
	else
	{
		cout << d[v];
	}
}