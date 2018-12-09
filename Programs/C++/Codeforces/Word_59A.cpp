#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int lower =0, upper = 0;
	for(char i:s)
	{
		if(isupper(i))
		{
			upper++;
		}
		else
		{
			lower++;
		}
	}
	if(upper>lower)
	{
		transform(s.begin(),s.end(), s.begin(),::toupper);
	}
	else
	{
		transform(s.begin(), s.end(), s.begin(),::tolower);
	}
	cout << s;
}