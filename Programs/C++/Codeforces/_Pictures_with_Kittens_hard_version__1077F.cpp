#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,x;
	cin >> n >> k >> x;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	int ans = 0;
	int maximum = -1;
	int i = 0;
	while(x--)
	{
		if(i == n)
		{
			ans+= maximum;
		}
		if((i+1) % k != 0)
		{
			maximum = max(maximum, arr[i]);
		}
		else
		{
			maximum = max(maximum, arr[i]);
			ans += maximum;
		}
		i++;
	}
	cout << ans;
}