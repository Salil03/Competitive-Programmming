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
		int n,m,q;
		cin >> n >> m >> q;
		vector<pair<int,int>> graph[n+1];
		int x,y,z;
		while(m--)
		{
			cin >> x >> y >> z;
			graph[x].push_back({y,z});
			graph[y].push_back({x,z});
		}
		int distance[n+1];
		distance[1] = 0;
		for(int i = 2; i<=n; i++)
		{
			distance[i] = INT_MAX;
		}
		bool visited[n+1] = {0};
		priority_queue<pair<int,int>> queue;
		queue.push({0,1});
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
		while(q--)
		{
			cin >> x;
			cout << distance[x] << "\n";
		}
	}
}