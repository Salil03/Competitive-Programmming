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
		cin >>n;
		string s;
		cin >> s;
		int sub1 = true;
		for(int i = 0; i<n; i++)
		{
			if(s[i] == '1')
			{
				sub1 = false;
				break;
			}
		}
		if(sub1)
		{
			if(n &1)
			{
				cout << n/2 + 1 << "\n";
				continue;
			}
			else
			{
				cout << n/2 << "\n";
				continue;
			}
		}
		int ans = 0;
		for(int i = 0; i<n; i++)
		{
			if(i == 0)
			{
				if(s[1] == '0'&& s[0] == '0')
				{
					ans++;
					s[0] = '1';
				}
			}
			else if(i == n-1)
			{
				if(s[n-2] == '0' && s[n-1] == '0')
				{
					ans++;
					s[n-1] = '1';
				}
			}
			else
			{
				if(s[i] == '0' && s[i+1] == '0' && s[i-1] == '0')
				{
					ans++;
					s[i] = '1';
				}
			}

		}
		cout << ans << "\n";
	}
}