#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,r, temp;
	cin >> n >> r;
	while(n--)
	{
		cin >> temp;
		if(temp >= r)
		{
			cout << "Good boi\n";
		}
		else
		{
			cout << "Bad boi\n";
		}
	}
}