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
	int t;
	cin >> t;
	while (t--)
	{
		lll n, k, p;
		cin >> n >> k >> p;
		lll arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		if (k & 1)
		{
			if (p == 1)
			{
				cout << *min_element(arr, arr + n) << "\n";
				continue;
			}
			else
			{
				cout << *max_element(arr, arr + n) << "\n";
				continue;
			}
		}
		if ((max_element(arr, arr + n) - arr == 1 || max_element(arr, arr + n) - arr == n - 2) && p == 0)
		{
			cout << *max_element(arr, arr + n) << "\n";
			continue;
		}
		if ((min_element(arr, arr + n) - arr == 1 || min_element(arr, arr + n) - arr == n - 2) && p == 1)
		{
			cout << *min_element(arr, arr + n) << "\n";
			continue;
		}
		if (p == 0)
		{
			lll maximum = max(arr[1], arr[n - 2]);
			for (int i = 1; i < n - 1; i++)
			{
				maximum = max(maximum, min(arr[i - 1], arr[i + 1]));
			}
			cout << maximum << "\n";
			continue;
		}
		if (p == 1)
		{
			lll minimum = min(arr[1], arr[n - 2]);
			for (int i = 1; i < n - 1; i++)
			{
				minimum = min(minimum, max(arr[i - 1], arr[i + 1]));
			}
			cout << minimum << "\n";
			continue;
		}
	}
}