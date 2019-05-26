#include <bits/stdc++.h>
using namespace std;
long long arr[100005];
void factorial()
{
    arr[0] = 1;
    arr[1] = 1;
    for (long long i = 2; i <= 100005; i++)
    {
        arr[i] = (arr[i - 1] % 1000000007) * (i % 1000000007);
    }
}
int main()
{
    long long t = 0, temp = 0;
    cin >> t;
    factorial();
    for (long long i = 0; i < t; i++)
    {
        cin >> temp;
        cout << arr[temp] % 1000000007 << "\n";
    }
}