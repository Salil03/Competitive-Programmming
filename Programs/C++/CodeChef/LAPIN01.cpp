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
		string s;
		cin >> s;
		int n = s.length();
		string first = s.substr(0, n/2);
		s = s.substr(ceil((float)n/2), n/2);
		sort(s.begin(), s.end());
		sort(first.begin(), first.end());
		if(first == s)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}