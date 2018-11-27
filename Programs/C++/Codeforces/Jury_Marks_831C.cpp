#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>k>>n;
	int t;
	int arr[k];
	set <int> c;
	for(int i=0; i<k; i++)
	{
		cin >> t;
		arr[i] = arr[i-1] + t;
	}
	for(int i=0;i<n;i++)
	{
		cin>>t;
		set<int>mmp;
		for(int j=0;j<k;j++)
		{
			int x = t-arr[j];
			if(!i || c.find(x) != c.end())
			{
				mmp.insert(x);
			}
		}
		c = mmp;
	}
	cout << c.size();
	return 0;
}