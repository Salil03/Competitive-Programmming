#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int ans = 0;
	for(char i:s)
	{
		if(i == '4' || i == '7')
		{
			ans++;
		}
	}
	s = to_string(ans);
	for(char i:s)
	{
		if(i != '4' && i != '7')
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}