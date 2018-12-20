#include<bits/stdc++.h>
using namespace std;
long long int lis(vector<long long int> arr)
{
	long long int ans = 1;
	long long int maximum = -1;
	for(long long int i = 1; i<arr.size(); i++)
	{
		if(i&1)
		{
			if(arr[i] < arr[i-1])
			{
				maximum = max(ans, maximum);
				ans = 1;
			}
			else
			{
				ans++;
			}
		}
		else
		{
			if(arr[i] > arr[i-1])
			{
				maximum = max(ans, maximum);
				ans = 1;
			}
			else
			{
				ans++;
			}
		}
	}
	maximum = max(maximum, ans);
	return maximum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n;
		cin >> n;
		vector<long long int> arr(n);
		long long int temp;
		for(long long int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		long long int result = -1;
		for(long long int i = 0; i<=n; i++)
		{
			arr.insert(arr.begin()+i, arr[i] +1);
			result = max(result, lis(arr));
			arr.erase(arr.begin() + i);
			arr.insert(arr.begin()+i, arr[i] -1);
			result = max(result, lis(arr));
			arr.erase(arr.begin() + i);
		}
		cout << result << "\n";
	}
}