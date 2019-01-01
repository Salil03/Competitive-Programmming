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
		int arr[n];
		for(int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		if(!next_permutation(arr, arr+n))
		{
			cout << -1 << "\n";
		}
		else
		{
			for(int i = 0; i<n; i++)
			{
				cout << arr[i];
			}
		}
		cout << "\n";
	}
}