#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,h;
	cin >> n >> h;
	int ans = 0;
	int temp;
	while(n--)
	{
		cin >> temp;
		if(temp > h)
		{
			ans += 2;
		}
		else
		{
			ans++;
		}
	}
	cout << ans;
}