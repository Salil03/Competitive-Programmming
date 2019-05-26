#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	cin >> a >> b;
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);
	bool c = a > b;
	bool d = a < b;
	if(c == 1)
	{
		cout << 1;
	}
	if(d == 1)
	{
		cout << -1;
	}
	if( c == 0 && d == 0)
	{
		cout << 0;
	}
}