#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int x =0, y =0, z =0;
	int temp;
	while(n--)
	{
		cin >> temp;
		x += temp;
		cin >> temp;
		y += temp;
		cin >> temp;
		z += temp;
	}
	if(x || y || z)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
}