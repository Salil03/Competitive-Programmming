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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int maximum = -1;
	double index = -1;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		int cnt = 0;
		while (i - j >= 0 && i + j < n)
		{
			if (s[i - j] == s[i + j])
			{
				cnt += 2;
			}
			else
			{
				break;
			}
			j++;
		}
		if (cnt - 1 > maximum)
		{
			maximum = cnt - 1;
			index = i;
		}
		if (i == n - 1)
		{
			break;
		}
		j = 0;
		cnt = 0;
		while (i - j >= 0 && i + 1 + j < n)
		{
			if (s[i - j] == s[i + 1 + j])
			{
				cnt += 2;
			}
			else
			{
				break;
			}
			j++;
		}
		if (cnt > maximum)
		{
			index = i + 0.5;
			maximum = cnt;
		}
	}
	cout << maximum << "\n";
	if (trunc(index) == index)
	{
		for (int i = index - maximum / 2; i <= index + maximum / 2; i++)
		{
			cout << s[i];
		}
	}
	else
	{
		index -= 0.5;
		for (int i = index - maximum / 2 + 1; i <= index + maximum / 2; i++)
		{
			cout << s[i];
		}
	}
}