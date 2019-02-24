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
		cin >> n >>k;
		int maximum = -1, minimum=INT_MAX;
		pair<int,int> arr[n]={{0,0}};
		int cakes[100001] = {0};
		for(int i=0; i<n;i++)
		{
			cin >> arr[i].first >> arr[i].second;
			maximum=max(maximum, arr[i].second);
			minimum=min(minimum,arr[i].first);
			for(int j = arr[i].first;j<=arr[i].second; j++)
			{
				cakes[j]++;
			}
		}
		int ans=-1;
		int current=0;
		for(int i=minimum; i<=maximum; i++)
		{
			if(cakes[i]== k)
			{
				current++;
			}
		}
		for(int i =0; i<n; i++)
		{
			int temp=0;
			for(int j = arr[i].first;j<=arr[i].second; j++)
			{
				if(cakes[j]==k+1)
				{
					temp++;
				}
				if(cakes[j] == k)
				{
					temp--;
				}
			}
			ans=max(temp,ans);
		}
		cout << ans+current << "\n";
	}
}