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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n, a;
		cin >> n >> a;
		string s = "";
		for (int i = 0; i < n; i++)
		{
			s += "9";
		}
		cout << s << endl;
		ll b;
		cin >> b;
		string c = "1";
		for (int i = 1; i < n; i++)
		{
			c += "0";
		}
		cout << c << endl;
		ll d;
		cin >> d;
		cout << stoll(s) - b - stoll(c) - a - d << endl;
		int verdict;
		cin >> verdict;
		if (verdict == -1)
		{
			return 0;
		}
	}
}