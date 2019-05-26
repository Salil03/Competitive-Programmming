#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a=0,b=0,c=0,d=0;
	bool temp;
	while(n--)
	{
		cin >> temp;
		if(temp)
		{
			a++;
		}
		else
		{
			b++;
		}
		cin >> temp;
		if(temp)
		{
			c++;
		}
		else
		{
			d++;
		}
	}
	cout << min(a,b) + min(c,d);
}