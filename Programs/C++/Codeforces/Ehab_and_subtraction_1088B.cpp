#include<bits/stdc++.h>
using namespace std;
void recur(int arr[], int n, int start,int k)
{
	if(k == 0 || start == n-1)
	{
		cout << "";
	}
	for(int i = start; i<n; i++)
	{
		if(arr[i])
		{
			cout << arr[i] - arr[start]<< "\n";
			recur(arr, n, i, k-1);
			break;
		}
		else if(i == n-1)
		{
			while(k--)
			{
				cout << 0 << "\n";
			}
			break;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	int arr[n+1] = {0};
	for(int i = 1; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+n);
	recur(arr, n+1, 0, k);
}