#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[4];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	sort(arr, arr+4);
	int ans = 0;
	for(int i = 1; i<4; i++)
	{
		if(arr[i] == arr[i-1])
		{
			ans++;
		}
	}
	cout << ans;
}