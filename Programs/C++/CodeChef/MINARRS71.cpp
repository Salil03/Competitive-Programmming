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

long long int freq(long long int arr[], long long int n)
{
	map<long long int, long long int> hashing;
	for (long long int i = 0; i < n; i++)
	{
		hashing[arr[i]]++;
	}

	long long int maximum = 0, temp = INT_MIN;
	for (auto i : hashing)
	{
		if (maximum <= i.second)
		{
			temp = i.first;
			maximum = i.second;
		}
	}

	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long int n;
		cin >> n;
		long long int arr[n];
		for (long long int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		long long int x = 1;
		long long int sum = 0;
		for (long long int i = 0; i < n; i++)
		{
			sum += (arr[i] ^ x);
		}
		cout << sum << "\n";
	}
}