int n = 20; //example
int sieve[n + 1];
memset(sieve, 0, sizeof(sieve)); //initialize to zero
for (int x = 2; x * x <= n; x++)
{
    if (sieve[x])
        continue;
    for (int u = x * x; u <= n; u += x)
    {
        sieve[u] = x;
    }
}
for (int i = 2; i <= n; i++)
{ //print all prime numbers
    if (!sieve[i])
        cout << i << "\n";
}