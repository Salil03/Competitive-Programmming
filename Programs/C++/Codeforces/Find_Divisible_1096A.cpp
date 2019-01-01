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
		int x,y;
		cin >> x >> y;
		if(y/2 <x)
		{
			continue;
		}
		cout << x << " " << 2*x << "\n";
	}
}