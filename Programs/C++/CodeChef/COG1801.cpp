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
		int n,p,k;
		cin >> n >> p >> k;
		int arr[n];
		for(int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr+n);
		int ans = 0;
		for(int i = 0; i<n-k; i++)
		{
			for(int j = i+k-1; j<n; j++)
			{
				if(arr[j] > arr[i]*p)
				{
					ans+= j-(i+k);
				}
			}
		}
		cout << ans << "\n";
	}
}