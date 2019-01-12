#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	bool found1 = false;
	bool found2 = false;
	for(int i = 0; i<n-2; i++)
	{
		if(s[i] == 'A' && s[i+1] == 'B')
		{
			for(int j = i+2;j<n; j++)
			{
				if(s[j] == 'B' && s[j+1] == 'A')
				{
					cout << "YES";
					return 0;
				}
			}
			break;
		}
	}
	for(int i = 0; i<n-2; i++)
	{
		if(s[i] == 'B' && s[i+1] == 'A')
		{
			for(int j = i+2;j<n; j++)
			{
				if(s[j] == 'A' && s[j+1] == 'B')
				{
					cout << "YES";
					return 0;
				}
			}
			cout << "NO";
			return 0;
		}
	}
	cout << "NO";
}