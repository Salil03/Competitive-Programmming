#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int  n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    if(n == 1)
    {
        cout << arr[0];
        return 0;
    }
    int ans = 0;
    for(int i = 0; i<n-1;i++)
    {
        ans |= arr[i];
    }
    cout << min(ans, arr[n-1]);
}