#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
	long long int t;
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
		long long int prefix[n + 1];
		prefix[0] = 0;
		for (long long int i = 1; i <= n; i++)
		{
			prefix[i] = prefix[i - 1] ^ arr[i - 1];
		}
		int maximum = *max_element(prefix, prefix + n + 1) + 2;
		pair<long long int, long long int> mp[maximum];
		long long int sum = 0;
		for (long long int i = 0; i <= n; i++)
		{
			if (mp[prefix[i]].second != 0)
			{
				sum += mp[prefix[i]].second * i - mp[prefix[i]].first - mp[prefix[i]].second;
			}
			mp[prefix[i]].first += i;
			mp[prefix[i]].second++;
		}
		cout << sum << "\n";
	}
}