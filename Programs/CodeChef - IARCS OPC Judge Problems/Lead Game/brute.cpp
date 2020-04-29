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
	int n;
	cin >> n;
	int s[n], t[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> t[i];
	}
	for (int i = 1; i < n; i++)
	{
		s[i] += s[i - 1];
		t[i] += t[i - 1];
	}
	pair<bool, int> win = {0, -1};
	for (int i = 0; i < n; i++)
	{
		if (s[i] > t[i])
		{
			if (s[i] - t[i] > win.second)
			{
				win.first = 0;
				win.second = s[i] - t[i];
			}
		}
		if (s[i] < t[i])
		{
			if (t[i] - s[i] > win.second)
			{
				win.first = 1;
				win.second = t[i] - s[i];
			}
		}
	}
	if (win.first)
	{
		cout << 2 << " " << win.second;
	}
	else
	{
		cout << 1 << " " << win.second;
	}
}