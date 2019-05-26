#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char s;
	while(cin >> s)
	{
		if(s == 'H' || s== 'Q' || s == '9')
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}