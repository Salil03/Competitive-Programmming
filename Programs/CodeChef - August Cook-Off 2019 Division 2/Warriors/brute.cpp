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
		while (q--)
		{
			int x;
			cin >> x;
			int cnt = 0;
			for (int i = 0; i < n; i++)
			{
				if (x <= arr[i])
				{
					break;
				}
				else
				{
					x = 2 * (x - arr[i]);
					cnt++;
				}
			}
			cout << cnt << "\n";
		}
	}
}