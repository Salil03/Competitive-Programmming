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
		int x,y,k,n;
		cin >> x >> y >> k >>n;
		bool lucky = false;
		x -= y;
		int p,q;
		while(n--)
		{
			cin >> p >> q;
			if(p >= x && q <= k)
			{
				lucky = true;
			}
		}
		if(lucky)
		{
			cout << "LuckyChef\n";
		}
		else
		{
			cout << "UnluckyChef\n";
		}
	}
}