#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    int temp;
    while(q--)
    {
        cin >> temp;
        auto it = lower_bound(arr, arr+n, temp);
        if(*it == temp)
        {
            cout << it-arr << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}