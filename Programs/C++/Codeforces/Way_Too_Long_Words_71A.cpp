#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	int l;
	while(n--)
	{
		cin >> s;
		l = s.length();
		if(l >10)
		{
			cout << s[0] << l - 2 << s[l-1] << "\n";
		}
		else
		{
			cout << s << "\n";
		}
	}
}