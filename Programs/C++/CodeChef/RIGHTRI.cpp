#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans =0;
	cin >> n;
	while(n--)
	{
		int x1,y1,x2,y2,x3,y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		int arr[3] = {(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2), (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2),(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)};
		sort(arr, arr+3);
		if(arr[2] == arr[1] + arr[0])
		{
			ans++;
		}
	}
	cout << ans;
}