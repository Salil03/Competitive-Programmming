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
	int n;
	cin >> n;
	lll a[n];
	lll b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	lll pref[n] = {b[0]};
	for (int i = 1; i < n; i++)
	{
		pref[i] = pref[i - 1] + b[i];
	}
	lll diff[n] = {0};
	diff[0] = a[0] - pref[0];
	for (int i = 1; i < n; i++)
	{
		diff[i] = max(diff[i - 1], a[i] - pref[i]);
	}
	lll sum[n] = {0};
	sum[n - 1] = a[n - 1] - pref[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		sum[i] = max(sum[i + 1], a[i] - pref[i]);
	}
	lll maximum = *max_element(a, a + n);
	for (int j = 1; j < n; j++)
	{
		maximum = max(maximum, a[j] + pref[j - 1] + diff[j - 1]);
	}
	maximum = max(maximum, a[0] + pref[n - 1] + sum[1]);
	for (int j = 1; j < n - 1; j++)
	{
		maximum = max(maximum, a[j] + pref[j - 1] + pref[n - 1] + sum[j + 1]);
	}
	cout << maximum;
}