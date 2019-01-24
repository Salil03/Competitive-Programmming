#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		i()
	}
	sort(arr, arr+n);
	int x = 1, y = 1;
	for(int i = n-1; i>=1; i--)
	{
		if(arr[i] == arr[i-1])
		{
			x *= arr[i];
		}
		else
		{
			if(y%arr[i] != 0)
			{
				y *= arr[i];
			}
		}

	}
	cout << x  << " "<< y/x;
}