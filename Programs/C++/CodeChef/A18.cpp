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
		int a,b;
		cin >> a >> b;
		if(b%a == 0)
		{
			cout << a << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
}