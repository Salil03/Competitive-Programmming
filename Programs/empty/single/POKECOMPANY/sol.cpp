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
const int INF = 0x3f3f3f3f;

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
	string s;
	lll maximum = 0, sum = 0;
	while (cin >> s)
	{
		lll n = s.length();
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'o')
			{
				sum += 100;
			}
			else if (s[i] == 'e')
			{
				sum += 10;
			}
			else if (s[i] == 'g')
			{
				sum += 1;
			}
			else if (s[i] == 'a')
			{
				sum += 0;
			}
			else if (s[i] == 'b')
			{
				sum -= 1;
			}
			else if (s[i] == 'i')
			{
				sum -= 10;
			}
			else if (s[i] == 'u')
			{
				sum -= 100;
			}
			else
			{
				break;
			}
			maximum = max(maximum, sum);
			if (sum <= 0)
			{
				sum = 0;
			}
		}
		if (s[n - 1] == '.')
		{
			cout << maximum << "\n";
			return 0;
		}
		else if (s[n - 1] == ',')
		{
			cout << maximum << "\n";
			maximum = 0;
			sum = 0;
		}
	}
}