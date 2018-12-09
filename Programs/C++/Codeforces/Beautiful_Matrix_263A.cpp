#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool temp;
	for(int i = 1; i<=5; i++)
	{
		for(int j =1; j<=5; j++)
		{
			cin >> temp;
			if(temp)
			{
				cout << abs(3 - i) + abs(3 - j);
				break;
			}
		}
	}
}