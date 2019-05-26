#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int arr[n], sum = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	int temp = abs(*max_element(arr, arr+n) - n) + min(*max_element(arr, arr+n), n);
	cout << sum - temp;
}