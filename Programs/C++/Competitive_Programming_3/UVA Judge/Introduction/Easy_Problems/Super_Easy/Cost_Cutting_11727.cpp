#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int i =0; i < t; i++)
	{
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr+3);
		cout << "Case " << i+1 << ": " << arr[1] << "\n";
	}
}