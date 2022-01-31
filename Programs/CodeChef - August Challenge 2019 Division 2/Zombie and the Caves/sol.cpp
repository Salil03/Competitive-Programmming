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

void addunity(long long arr[], long long n, long long low_bound, long long upbound)
{
	arr[low_bound] += 1;
	if (upbound != n - 1)
	{
		arr[upbound + 1] -= 1;
	}
}

void calcprefix(long long arr[], long long n)
{
	for (int i = 1; i < n; i++)
	{
		arr[i] += arr[i - 1];
	}
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
		long long n;
		cin >> n;
		long long arr[n];
		long long final[n] = {0};
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		long long zomb[n];
		for (int i = 0; i < n; i++)
		{
			cin >> zomb[i];
		}
		for (long long i = 0; i < n; i++)
		{
			addunity(final, n, max((long long)0, i - arr[i]), min(n - 1, i + arr[i]));
		}
		calcprefix(final, n);
		sort(final, final + n);
		sort(zomb, zomb + n);
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (final[i] != zomb[i])
			{
				flag = false;
			}
		}
		if (flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}