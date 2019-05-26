#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int x,y, sum=0;
	bool coincide = true;
	for(int i = 1; i<=n; i++)
	{
		if(i&1)
		{
			cin >> x;
			sum +=x;
		}
		else
		{
			cin >> y;
			sum += y;
			if(coincide == true && x != -y)
			{
				coincide = false;
			}
		}
	}
	if(sum > 0)
	{
		cout << "first";
	}
	else if(sum <0)
	{
		cout << "second";
	}
	else if(sum == 0)
	{
		if(coincide == true)
		{
			cout << "second";
		}
		else
		{
			cout << "first";
		}
	}
}