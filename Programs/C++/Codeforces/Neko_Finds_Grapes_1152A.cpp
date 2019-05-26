#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://codeforces.com/contest/1152/problem/A

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	long long odd1 = 0, even1 = 0;
	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;
		if (temp & 1)
		{
			odd1++;
		}
		else
		{
			even1++;
		}
	}
	long long odd2 = 0, even2 = 0;
	for (int i = 0; i < m; i++)
	{
		long long temp;
		cin >> temp;
		if (temp & 1)
		{
			odd2++;
		}
		else
		{
			even2++;
		}
	}
	cout << min(odd1, even2) + min(odd2, even1);
}
