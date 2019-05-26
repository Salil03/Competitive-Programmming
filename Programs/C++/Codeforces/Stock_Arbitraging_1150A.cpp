#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://codeforces.com/contest/1150/problem/A

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, r;
	cin >> n >> m >> r;
	int init = r;
	int minimum = INT_MAX;
	while (n--)
	{
		int temp;
		cin >> temp;
		minimum = min(minimum, temp);
	}
	int buy = r / minimum;
	r %= minimum;
	int maximum = -1;
	while (m--)
	{
		int temp;
		cin >> temp;
		maximum = max(temp, maximum);
	}
	r += buy * maximum;
	if (r <= init)
	{
		cout << init;
	}
	else
	{
		cout << r;
	}
}