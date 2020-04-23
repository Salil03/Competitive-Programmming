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
const long long int INF = 0x3f3f3f3f3f3f3f3f;

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
	lll t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		lll n, k;
		cin >> n >> k;
		lll a[n + 1];
		int sum[200010] = {0};
		int arr[200010] = {0};
		int first[k + 3] = {0};
		int second[k + 3] = {0};
		for (int j = 1; j <= (n / 2); j++)
		{
			cin >> a[j];
			first[a[j]]++;
		}
		for (int j = (n / 2); j <= n; j++)
		{
			cin >> a[j];
			second[a[j]]++;
		}
		for (int j = 1; j <= (n / 2); j++)
		{
			sum[a[j] + a[n - j + 1]]++;
		}
		multiset<int> s;
		for (int j = 1; j <= (n / 2); j++)
		{
			int index = min(a[j], a[n - j + 1]);
			s.insert(index);
		}
		int ret = n;
		int tc = 0;
		int oc = 0;
		for (int j = 2; j <= (2 * k); j++)
		{
			lll no_change = sum[j];
			lll two_change = 0;
			int idx = distance(s.begin(), upper_bound(s.begin(), s.end(), j)) - 1;
			two_change = idx;
			lll one_change = n - (no_change) - (two_change);
			lll total = 2 * one_change + 2 * two_change;
			if (ret > total)
			{
				ret = total;
				tc = two_change;
				oc = one_change;
			}
		}
		//cout << tc << "\n";
		//cout << oc << "\n";
		cout << ret << "\n";
	}
}