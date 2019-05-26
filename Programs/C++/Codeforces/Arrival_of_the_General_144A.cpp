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
	}
	auto maximum = max_element(arr, arr+n) - arr;
	int minimum_val = INT_MAX;
	int minimum = 0;
	for(int i = 0; i<n; i++)
	{
		if(arr[i] <= minimum_val)
		{
			minimum_val = arr[i];
			minimum = i;
		}
	}
	if(minimum > maximum)
	{
		cout << maximum - 1 +n - minimum;
	}
	else
	{
		cout << maximum - 1 +n - minimum -1;
	}
}