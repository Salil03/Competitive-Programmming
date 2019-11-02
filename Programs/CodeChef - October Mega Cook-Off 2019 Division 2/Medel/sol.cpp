//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int maximum = -1, minimum = INT_MAX, arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		if (arr - max_element(arr, arr + n) < arr - min_element(arr, arr + n))
		{
			cout << *min_element(arr, arr + n) << " " << *max_element(arr, arr + n) << "\n";
		}
		else
		{
			cout << *max_element(arr, arr + n) << " " << *min_element(arr, arr + n) << "\n";
		}
	}
}