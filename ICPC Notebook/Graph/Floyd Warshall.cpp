//to init distance array
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        if (i == j)
        {
            distance[i][j] = 0;
        }
        else if
        {
            (adj[i][j]) distance[i][j] = adj[i][j];
        }
        else
        {
            distance[i][j] = INF;
        }
    }
}
//to calculate values
for (int k = 1; k <= n; k++)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
        }
    }
}