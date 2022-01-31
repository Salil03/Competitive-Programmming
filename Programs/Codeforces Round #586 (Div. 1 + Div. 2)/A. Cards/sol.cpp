#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

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
	int len;
	cin >> len;
	string s;
	cin >> s;
	int z = 0, e = 0, r = 0, o = 0, n = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'z')
		{
			z++;
		}
		if (s[i] == 'e')
		{
			e++;
		}
		if (s[i] == 'r')
		{
			r++;
		}
		if (s[i] == 'o')
		{
			o++;
		}
		if (s[i] == 'n')
		{
			n++;
		}
	}
	while (n--)
	{
		cout << 1 << " ";
		o--;
		e--;
	}
	while (z--)
	{
		cout << 0 << " ";
	}
}