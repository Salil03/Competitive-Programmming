#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int d,n;
	cin >> n >> d;
	long long int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+n);
	long long int ans = 0;
	for(int i = 0; i<n-1; i++)
	{
		if(arr[i+1] - arr[i] <= d)
		{
			ans++;
			i++;
		}
	}
	cout << ans;
}