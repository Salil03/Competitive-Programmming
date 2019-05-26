#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x = 0;
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		if(s[0] == '-' || s[1] == '-' || s[2] == '-')
		{
			x--;
		}
		else
		{
			x++;
		}
	}
	cout << x;
}