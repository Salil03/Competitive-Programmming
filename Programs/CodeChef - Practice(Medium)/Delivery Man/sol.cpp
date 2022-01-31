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
	int n, x, y;
	cin >> n >> x >> y;
	pair<int, int> arr[n];
	int a[n], b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		arr[i].first = a[i] - b[i];
		arr[i].second = i;
	}
	sort(arr, arr + n);
	ll ans = 0;
	for (int i = 0; i < y; i++)
	{
		ans += b[arr[i].second];
	}
	for (int i = y; i < min(n, y + x); i++)
	{
		ans += a[arr[i].second];
	}
	lll maximum = ans;
	ans = 0;
	for (int i = n - 1; i >= max(0, n - x); i--)
	{
		ans += a[arr[i].second];
	}
	for (int i = n - x - 1; i >= max(0, n - x - y); i--)
	{
		ans += b[arr[i].second];
	}
	maximum = max(ans, maximum);
	cout << maximum;
}