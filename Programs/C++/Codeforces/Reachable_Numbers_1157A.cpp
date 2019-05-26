#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://codeforces.com/contest/1157/problem/A

Solution Begins here
*/

long long ans = 0;

void func(long long n)
{
	if (n == 1)
	{
		return;
	}
	n++;
	while (n % 10 == 0)
	{
		n /= 10;
	}
	ans++;
	func(n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	if (n < 10)
	{
		cout << 9;
		return 0;
	}
	func(n);
	cout << ans + 1;
}