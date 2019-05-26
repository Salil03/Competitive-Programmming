#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,d;
	cin >> n >> d;
	string s;
	cin >> s;
	int last = 0;
	for(int i = 0; i<n; i++)
	{
		if(s[i] == '1')
		{
			if(i-last >d)
			{
				cout << -1;
				return 0;
			}
			else
			{
				last = i;
			}
		}
	}
}