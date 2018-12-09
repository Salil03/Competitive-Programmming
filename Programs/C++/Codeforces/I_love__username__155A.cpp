#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	n--;
	int minimum, maximum;
	cin >> minimum;
	maximum = minimum;
	int temp, ans = 0;
	while(n--)
	{
		cin >> temp;
		if(temp < minimum)
		{
			ans++;
			minimum = temp;
		}
		else if(temp > maximum)
		{
			ans++;
			maximum = temp;
		}
	}
	cout << ans;
}