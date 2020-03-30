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
	lll n;
	cin >> n;
	pair<lll, lll> a[n], b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(a, a + n);
	sort(b, b + n);
	lll arr[n] = {};
	lll sir = n - 1, nav = n - 1, fin = 0, low = 0, cnt = 0;
	while (fin < n)
	{
		if (a[sir].first > b[nav].first)
		{
			arr[a[sir].second] = b[nav].second + 1;
			sir--;
			nav--;
			fin++;
			cnt++;
		}
		else
		{
			arr[a[low].second] = b[nav].second + 1;
			nav--;
			low++;
			fin++;
		}
	}
	cout << cnt << "\n";
	for (int i : arr)
	{
		cout << i << "\n";
	}
}