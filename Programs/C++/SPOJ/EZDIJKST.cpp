#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		vector<pair<int,int>> graph[n+1];
		int x,y,z;
		while(m--)
		{
			cin >> x >> y >> z;
			graph[x].push_back({y,z});
		}
		cin >> x >> y;
		int distance[n+1];
		for(int i = 0; i<=n; i++)
		{
			distance[i] = 100005;
		}
		distance[x] = 0;
		bool visited[n+1] = {0};
		priority_queue<pair<int,int>> queue;
		queue.push({0,x});
		while(!queue.empty())
		{
			int a = queue.top().second;
			queue.pop();
			if(visited[a])
			{
				continue;
			}
			visited[a] = true;
			for(auto u: graph[a])
			{
				int b = u.first;
				int w = u.second;
				if(distance[b] > distance[a] + w)
				{
					distance[b] = distance[a] +w;
					queue.push({-distance[b], b});
				}
			}
		}
		if(distance[y] == 100005)
		{
			cout << "NO\n";
			continue;
		}
		cout << distance[y] << "\n";
	}
}