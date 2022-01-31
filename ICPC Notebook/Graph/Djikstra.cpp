queue<pair<int, int>> q;
for (int i = 1; i <= n; i++)
{
    distance[i] = INF;
}
distance[x] = 0;
q.push({0, x});
while (!q.empty())
{
    int a = q.top().second;
    q.pop();
    if (visited[a])
    {
        continue;
    }
    visited[a] = true;
    for (auto u : adj[a])
    {
        int b = u.first, w = u.second;
        if (distance[a] + w < distance[b])
        {
            distance[b] = distance[a] + w;
            q.push({-distance[b], b});
        }
    }
}
