#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		unsigned long long int n,a,b,k;
		cin >> n >> a >> b >> k;
		unsigned long long int lcm = (a*b)/(__gcd(a,b));
		if(n/a + n/b - 2*(n/lcm) >= k)
		{
			cout << "Win\n";
		}
		else
		{
			cout << "Lose\n";
		}
	}
}