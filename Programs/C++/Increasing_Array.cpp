#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long m, n = 0;
    cin >> m;
    vector<long long> numbers;
    for (long long i = 0; i < m; i++)
    {
        cin >> n;
        numbers.push_back(n);
    }
    n = 0;
    for (long long i = 1; i < m; i++)
    {
        if (numbers[i] < numbers[i - 1])
        {
            n += numbers[i - 1] - numbers[i];
            numbers[i] += numbers[i - 1] - numbers[i];
        }
    }
    cout << n;
}