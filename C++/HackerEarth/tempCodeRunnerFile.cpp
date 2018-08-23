#include <bits/stdc++.h>
using namespace std;
long long arr[1000000];
long long factorial(long long x)
{
    arr[0] = 1;
    arr[1] = 1;
    if (x == 1 || x == 0)
    {
        return 1;
    }
    for (long long i = 2; i <= x; i++)
    {
        arr[i] = arr[i - 1] * i;
    }
    return arr[x];
}
int main()
{
    long long t = 0, temp = 0;
    cin >> t;
    for (long long i = 0; i < t; i++)
    {
        cin >> temp;
        cout << factorial(temp) << "\n";
    }
}