#include <bits/stdc++.h>
using namespace std;
int chocolates[100000];
int arr[100002];
void dp(int n)
{
    chocolates[0] = arr[0];
    for(int i=1; i <=n; i++)
    {
        chocolates[i] = max(arr[i-1] + chocolates[i-1], arr[i]);
    }
}
int main()
{
    int n =0;
    cin >> n;
    for(int i =0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp(n-1);
    cout << chocolates[n-1];
}
