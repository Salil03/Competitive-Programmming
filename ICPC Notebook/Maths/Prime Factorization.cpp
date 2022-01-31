vector<int> factors(int n)
{
    vector<int> f;
    while (n % 2 == 0)
    {
        f.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            f.push_back(i);
            n = n / i;
        }
    }
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        f.push_back(n);
    return f;
}
