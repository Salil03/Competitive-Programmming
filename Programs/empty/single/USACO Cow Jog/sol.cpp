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
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	lll n, t;
	cin >> n >> t;
	pair<lll, lll> arr[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	lll cnt = 1;
	for (lll i = 0; i < n - 1; i++)
	{
		for (lll j = i + 1; j < n; j++)
		{
			int pos = arr[j].first - arr[i].first;
			int rel = arr[i].second - arr[j].second;
			if (rel == 0)
			{
				continue;
			}
			else if (pos / rel >= t || rel < 0)
			{
				continue;
			}
			else
			{
				cnt++;
			}
		}
	}
	cout << cnt;
}