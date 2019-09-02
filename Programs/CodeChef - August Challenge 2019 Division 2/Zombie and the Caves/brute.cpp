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
			for (long long j = max((long long)0, i - arr[i]); j < min(n, i + arr[i] + 1); j++)
			{
				final[j]++;
			}
		}
		sort(final, final + n);
		sort(zomb, zomb + n);
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (final[i] != zomb[i])
			{
				flag = false;
				break;
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