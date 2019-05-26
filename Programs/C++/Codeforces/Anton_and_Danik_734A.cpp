#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int anton = 0, danik = 0;
	char temp;
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		if(temp == 'A')
		{
			anton++;
		}
		else
		{
			danik++;
		}
	}
	if(anton > danik)
	{
		cout << "Anton";
	}
	else if(danik > anton)
	{
		cout << "Danik";
	}
	else
	{
		cout << "Friendship";
	}
}