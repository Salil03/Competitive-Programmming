#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = sqrt(n); i>0; i--)
		{
			if(n%i == 0)
			{
				cout << abs(i-(n/i)) << "\n";
				break;
			}
		}
	}	
}