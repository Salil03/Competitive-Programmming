//graph stored as vector<int> adj[N];
//queue<int> q;
//bool visited[n];
//int distance[n];
visited[x] = true;
distance[x] = 0;
q.push(x);
while (!q.empty())
{
    int s = q.front();
    q.pop();
    for (auto u : adj[s])
    {
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;
        distance[u] = distance[s] + 1;
        q.push(u);
    }
}