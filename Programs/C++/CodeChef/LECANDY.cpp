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
		int n,c,temp;
		cin >> n >> c;
		while(n--)
		{
			cin >> temp;
			c -= temp;
		}
		if(c <0)
		{
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n";
		}
	}
}