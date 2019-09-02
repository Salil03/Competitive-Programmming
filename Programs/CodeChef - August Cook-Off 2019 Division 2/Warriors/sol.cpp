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
		int n, q;
		cin >> n >> q;
		long long arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		long long prefix[n + 1];
		prefix[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			prefix[i] = prefix[i - 1] + arr[i - 1];
		}
		for (int i = 1; i <= n; i++)
		{
			prefix[i] = 1 + ((prefix[i] - 1) / i);
			watch(prefix[i]);
		}
		while (q--)
		{
			long long x;
			cin >> x;
			if (x <= prefix[1])
			{
				cout << 0 << "\n";
				continue;
			}
			if (x > prefix[n])
			{
				cout << n << "\n";
				continue;
			}
			auto near = lower_bound(prefix, prefix + n + 1, x);
			if (*near == x)
			{
				cout << near - prefix - 1 << "\n";
			}
			else
			{
				cout << near - prefix << "\n";
			}
		}
	}
}