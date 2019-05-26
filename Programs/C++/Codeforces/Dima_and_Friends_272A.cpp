#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int sum = 0, temp;
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		sum += temp;
	}
	int ans = 0;
	for(int i = 1; i<6; i++)
	{
		if((sum + i ) % (n+1) != 1)
		{
			ans++;
		}
	}
	cout << ans;
}