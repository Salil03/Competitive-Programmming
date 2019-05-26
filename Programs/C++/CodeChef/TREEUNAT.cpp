#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,temp;
        cin >> n;
        int arr[3];
        for(int i = 0; i<n; i++)
        {
            cin >> temp;
            arr[temp]++;
        }
        sort(arr, arr+3);
        for(int i =1; i<n; i++)
        {
            cin >> temp >> temp;   
        }
        if(arr[0] >= n-2)
        {
            cout << 0 << "\n";
        }
    }
}