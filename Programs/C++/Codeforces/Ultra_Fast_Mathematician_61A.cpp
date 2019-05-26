#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string n,m, ans = "";
	cin >> n >> m;
	int len = n.length();
	for(int i = 0; i<len; i++)
	{
		if(n[i] == m[i])
		{
			ans += '0';
		}
		else
		{
			ans += '1';
		}
	}
	cout << ans;
}