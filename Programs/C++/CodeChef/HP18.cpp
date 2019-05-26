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
		int n,a,b, temp, alice = 0, bob = 0;
		cin >> n >> a >> b;
		while(n--)
		{
			cin >> temp;
			if(temp % a == 0)
			{
				bob++;
			}
			else if(temp % b == 0)
			{
				alice++;
			}
		}
		if(bob > alice)
		{
			cout << "BOB\n";
		}
		else
		{
			cout << "ALICE\n";
		}
	}
}