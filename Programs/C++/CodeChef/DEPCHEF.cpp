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
		int n;
		cin >> n;
		int a[n];
		int d[n];
		for(int i  =0 ;i<n; i++)
		{
			cin >> a[i];
		}
		for(int i = 0; i<n; i++)
		{
			cin >> d[i];
		}
		int maximum = -10;
		if(d[0] > a[n-1] + a[1])
		{
			maximum = max(d[0], maximum);
		}
		if(d[n-1] > a[0] + a[n-2])
		{
			maximum = max(d[n-1], maximum);
		}
		for(int i = 1; i<n-1; i++)
		{
			if(d[i] > a[i-1] + a[i+1])
			{
				maximum = max(d[i], maximum);
			}
		}
		if(maximum == -10)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << maximum << "\n";
		}
	}
}