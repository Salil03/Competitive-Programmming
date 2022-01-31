int cutRod(int price[], int n)
{
    int val[n + 1]; //dp table with optimal value for rod of length 0...n
    val[0] = 0;     //base case
    for (int i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            max_val = max(max_val, price[j] + val[i - j - 1]);
        }
        val[i] = max_val; //answer for i in range 0...n
    }
    return val[n]; //answer
}
