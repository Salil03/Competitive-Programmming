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
		int arr1[n];
		int arr2[n];
		int scores[n] = {0};
		cin >> arr1[0] >> arr2[0];
		for(int i = 1; i<n; i++)
		{
			cin >> arr1[i] >> arr2[i];
			for(int j = i-1; j>-1; j--)
			{
				if(arr1[i] == arr1[j] && arr2[i] == arr2[j])
				{
					scores[i]++;
					scores[j]++;
				}
				else if(arr1[i] < arr1[j] && arr2[i]<arr2[j])
				{
					scores[i]++;
					scores[j]++;
				}
				else if(arr1[j] < arr1[i] && arr2[j] < arr2[i])
				{
					scores[i]++;
					scores[j]++;
				}
				else if(arr1[i] <= arr1[j] && arr2[i] >= arr2[j])
				{
					scores[i] += 2;
				}
				else if(arr1[j] <= arr1[i] && arr2[j] <= arr2[j])
				{
					scores[j] += 2;
				}
			}
		}
		for(int i:scores)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
}