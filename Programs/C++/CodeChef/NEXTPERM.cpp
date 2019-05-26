#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	int arr[n];
	while(k--)
	{
		for(int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		next_permutation(arr, arr+n);
		for(int i = 0; i<n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
}