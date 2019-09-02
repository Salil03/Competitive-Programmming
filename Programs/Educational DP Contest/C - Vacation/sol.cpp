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
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	int prea = a[0];
	int preb = b[0];
	int prec = c[0];
	int newa = INT_MIN;
	int newb = INT_MIN;
	int newc = INT_MIN;
	for (int i = 1; i < n; i++)
	{
		newa = a[i] + max(preb, prec);
		newb = b[i] + max(prea, prec);
		newc = c[i] + max(prea, preb);
		prea = newa;
		preb = newb;
		prec = newc;
	}
	cout << max({prea, preb, prec});
}