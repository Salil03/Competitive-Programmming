#include <bits/stdc++.h>
using namespace std;
int fee[10000];
int arr[10000];
void best()
{
    arr[0] = fee[0];
    arr[1] = fee[1];
    for (int i = 2; i <= 10000; i++)
    {
        arr[i] = max({arr[i - 2] + fee[i - 2], arr[i - 1] + fee[i - 1], fee[i]});
    }
}
int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> fee[i];
    }
    best();
    cout << arr[n];
}