int knapSack(int w, int weight[], int value[], int n)
{
    int knap[n + 1][w + 1]; //dp table
    // Build table K[][] in bottom up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                knap[i][j] = 0;
            }
            else if (weight[i - 1] <= j)
            {
                knap[i][j] = max(value[i - 1] + knap[i - 1][j - weight[i - 1]], knap[i - 1][j]);
            }
            else
            {
                knap[i][j] = knap[i - 1][j];
            }
        }
    }
    return knap[n][w]; //answer
}