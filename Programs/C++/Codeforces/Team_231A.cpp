#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int total = 0;
	while(n--)
	{
		int a,sum = 0;
		cin >>a;
		sum += a;
		cin >> a;
		sum += a;
		cin >> a;
		sum += a;
		if(sum > 1)
		{
			total++;
		}
	}
	cout << total;
}