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

/*
$alil03

URL: url

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string n;
		cin >> n;
		lll ans = 0, len = n.length();
		for (int i = 0; i < len; i++)
		{
			if (n[i] != 'x')
			{
				ans += n[i] - '0';
			}
		}
		int mod = ans % 9;
		int index = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			if (n[i] == 'x')
			{
				n[i] = to_string(9 - mod)[0];
				index = i;
				break;
			}
		}
		for (int i = 0; i < index; i++)
		{
			if (n[i] == 'x')
			{
				n[i] = '9';
			}
		}
		cout << n << "\n";
	}
}