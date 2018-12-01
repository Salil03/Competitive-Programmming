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
		string a,b;
		cin >> a >> b;
		if(a.length() > b.length())
		{
			int last = 0;
			for(char i: a)
			{
				if(i == b[last])
				{
					last++;
				}
			}
			if(last == b.length())
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else if(a.length() < b.length())
		{
			int last = 0;
			for(char i: b)
			{
				if(i == a[last])
				{
					last++;
				}
			}
			if(last == a.length())
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			if(a == b)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}