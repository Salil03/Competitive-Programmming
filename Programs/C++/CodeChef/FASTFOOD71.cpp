#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/LTIME71B/problems/FASTFOOD

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
		int n;
		cin >> n;
		long long a[n];
		long long b[n];
		cin >> a[0];
		for (int i = 1; i < n; i++)
		{
			cin >> a[i];
			a[i] += a[i - 1];
		}
		cin >> b[0];
		for (int i = 1; i < n; i++)
		{
			cin >> b[i];
			b[i] += b[i - 1];
		}
		long long maximum = b[n - 1];
		for (int i = 1; i <= n; i++)
		{
			maximum = max(maximum, a[i - 1] + b[n - 1] - b[i - 1]);
		}
		cout << maximum << "\n";
	}
}