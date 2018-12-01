#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
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
		cpp_int a,b;
		cin >> a >> b;
		cout << __gcd(a, b%a) << "\n";
	}
}