#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[10];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+10);
    cout << "The sorted array is \n";
    for(int i = 0; i<10; i++)
    {
      cout  << arr[i] << "\n";
    }
}
