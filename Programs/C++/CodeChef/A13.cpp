#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[4];
	for(int i = 0; i<4; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+4);
	if(arr[0] + arr[1] + arr[2] == arr[3])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}