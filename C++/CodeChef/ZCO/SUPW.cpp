#include <bits/stdc++.h>
using namespace std;
long long work[2000000];
long long arr[2000000];
void minutes()
{
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    for (long long i = 3; i <= 200050; i++)
    {
        arr[i] = min({work[i - 3] + arr[i - 3], work[i - 2] + arr[i - 2], work[i - 1] + arr[i - 1]});
    }
}
int main()
{
    long long n = 0, ans = 0;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> work[i];
    }
    minutes();
    cout << arr[n];
}