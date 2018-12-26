#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int temp, maximum = -1, last = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		if(ceil(temp/m) >= maximum)
		{
			maximum = ceil(temp/m);
			last = i;
		}
	}
	cout << last + 1;
}