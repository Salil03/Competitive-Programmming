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
		int ans = 0;
		for(int i = 0; i<n; i++)
		{
			if(s[i] == '1' || s[i-1] == '1'|| s[i+1] == '1')
			{
				ans++;
			}
		}
		cout << n-ans << "\n";
	}
}