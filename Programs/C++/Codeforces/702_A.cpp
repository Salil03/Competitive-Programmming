#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	int ans = 1,maximum = -1;
	for(int i = 0; i<n-1; i++)
	{
		if(arr[i] >= arr[i+1])
		{
			maximum = max(maximum, ans);
			ans =1;
		}
		else
		{
			ans++;
		}
	}
	cout << max(maximum,ans);
}