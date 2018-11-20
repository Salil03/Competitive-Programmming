#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    int arr[t];
    for(int i = 0; i<t; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+t);
    for(int i:arr)
    {
        cout << i << "\n";
    }
}