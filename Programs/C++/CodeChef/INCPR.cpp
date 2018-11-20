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
        int n,k;
        cin >> n >> k;
        k--;
        int arr[n];
        for(int i = 0; i<n; i++)
        {
            cin >> arr[i];
        }
        int ans = 1;
        for(int i:arr)
        {
            if(i < arr[k])
            {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}