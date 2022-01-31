int coin(int S[], int m, int n)
{
    int table[n + 1];
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for (int i : S) //for each coin is S
        for (int j = i; j <= n; j++)
            table[j] += table[j - i];
    return table[n]; //answer
}