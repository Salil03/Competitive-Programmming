#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >>t;
	while(t--)
	{
		int n;
		cin >> n;
		int sum = 0, temp;
		while(n--)
		{
			cin >> temp;
			sum += temp;
		}
		if(sum >= 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}