#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int height[n];
	int pressure[n];
	cin >> pressure[0] >> height[0];
	int x,y;
	for(int i = 1; i<n; i++)
	{
		cin >> x >> y;
		pressure[i] =  x;
		height[i] = height[i-1] + y;
	}
	int q;
	cin >>q;
	while(q--)
	{
		cin >> x >> y;
		int sum = 0;
		while(x < y)
		{
			auto it = upper_bound(height, height+n, x);
			int start = min(y, height[it - height]);
			sum += pressure[it-height] * 10 * (start - x);
			x += (start - x);
		}
		cout << sum << "\n";
	}
}