#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned long long int n,m;
	cin >> n >> m;
	unsigned long long int a[n];
	unsigned long long int b[m];
	for(unsigned long long int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	for(unsigned long long int i = 0; i<m; i++)
	{
		cin >> b[i];
	}
	unsigned long long int sum[n+m-1];
	unsigned long long int i = 0;
	unsigned long long int ans = 0;
	for(unsigned long long int k = 0; k<n; k++)
	{
		for(unsigned long long int j = 0; j<m; j++)
		{
			if(ans >= n+m -1)
			{
				return 0;
			}
			if(!binary_search(sum, sum+i, a[k] + b[j]))
			{
				ans++;
				cout << k << " "<< j << "\n";
				sum[i] = a[k]+b[j];
				i++;
			}
		}
	}
}