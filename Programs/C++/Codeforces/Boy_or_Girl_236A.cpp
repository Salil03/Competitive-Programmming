#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	set<char> s;
	char temp;
	while(cin >> temp)
	{
		s.insert(temp);
	}
	if(s.size() & 1)
	{
		cout << "IGNORE HIM!";
	}
	else
	{
		cout << "CHAT WITH HER!";
	}
}