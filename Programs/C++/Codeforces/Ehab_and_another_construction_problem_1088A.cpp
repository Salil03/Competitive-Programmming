#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x;
	cin >> x;
	for(int a = 1; a<=x; a++)
	{
		for(int b = 1; b<=x; b++)
		{
			if(a%b == 0 && a*b >x && float(a/b) < x)
			{
				cout << a << " "<< b;
				return 0;
			}
		}
	}
	cout << -1;
}