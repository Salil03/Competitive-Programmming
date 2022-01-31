int minCoins(int coins[], int n)
{
    int table[n + 1];
    table[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        table[i] = INT_MAX; //initialize all values to Infinity
        // Go through all coins smaller than i
        for (int c : coins)
        {
            if (i - c >= 0)
            {
                table[i] = min(table[i], table[i - c] + 1);
            }
        }
    }
    return table[n];
}