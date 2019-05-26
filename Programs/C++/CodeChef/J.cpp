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
		double p,s;
		cin >> p >> s;
		cout << fixed << setprecision(2) << 0.0833333333*(p-sqrt(p*p - 24*s)) * 0.0833333333*(p-sqrt(p*p - 24*s)) * 0.0833333333*(2*sqrt(p*p - 24*s) + p) << "\n"; 
	}
}