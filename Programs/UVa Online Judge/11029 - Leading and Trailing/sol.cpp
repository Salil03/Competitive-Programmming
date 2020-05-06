//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
lll binary(lll x, lll power, lll n)
{
	if (power == 0)
	{
		return 1;
	}
	if (power & 1)
	{
		power--;
		return ((x % n) * (binary(x, power / 2, n) % n) * (binary(x, power / 2, n) % n)) % n;
	}
	else
	{
		return ((binary(x, power / 2, n) % n) * (binary(x, power / 2, n) % n)) % n;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		lll a, b;
		cin >> a >> b;
		double num = b * log10(a) - (lll)(b * log10(a)) + 2;
		string c = to_string(pow(10, num));
		cout << c[0] << c[1] << c[2] << "...";
		string s = to_string(binary(a, b, 1000));
		if (s.length() == 1)
		{
			cout << "00" << s;
		}
		else if (s.length() == 2)
		{
			cout << 0 << s;
		}
		else
		{
			cout << s;
		}
		cout << "\n";
	}
}