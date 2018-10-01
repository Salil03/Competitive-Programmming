#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int temp = 0;
    cin >> temp;
    auto match = find(arr, arr + n, temp);
    cout << match - arr;
}