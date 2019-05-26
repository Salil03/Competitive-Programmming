#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/LTIME71B/problems/MINARRS

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
		long long int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		long long int sum = 0, minimum = LLONG_MAX;
		for (long long int i = 1; i < 2000; i++)
		{
			int j = 0;
			while (sum < minimum && j < n)
			{
				sum += (arr[j] ^ i);
				j++;
			}
			minimum = min(sum, minimum);
			sum = 0;
		}
		cout << minimum << "\n";
	}
}