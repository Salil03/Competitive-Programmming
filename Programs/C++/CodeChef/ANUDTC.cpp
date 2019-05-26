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
		int n;
		cin >> n;
		if(360%n == 0 && n<= 360)
		{
			cout << "y ";
		}
		else
		{
			cout << "n ";
		}
		if(n<= 360)
		{
			cout << "y ";
		}
		else
		{
			cout << "n ";
		}
		if(n*(n+1)/2 <= 360)
		{
			cout << "y";
		}
		else
		{
			cout << "n";
		}
		cout << "\n";
	}
}