#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://codeforces.com/problemset/problem/363/B

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int sum = 0, index = 0;
	for (int i = 0; i < k; i++)
	{
		sum += arr[i];
	}
	int minimum = sum;
	for (int i = k; i < n; i++)
	{
		sum += arr[i];
		sum -= arr[i - k];
		if (minimum >= sum)
		{
			minimum = sum;
			index = i - k + 1;
		}
	}
	cout << index + 1;
}