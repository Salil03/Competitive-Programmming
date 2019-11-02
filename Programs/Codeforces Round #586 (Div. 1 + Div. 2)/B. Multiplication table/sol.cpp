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
	int n;
	cin >> n;
	long long int arr[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		long long int factor = arr[0][i];
		if (i == 0)
		{
			factor = arr[1][i];
		}
		for (int j = 0; j < n; j++)
		{
			if (j == i)
			{
				continue;
			}
			else
			{
				factor = __gcd(factor, arr[j][i]);
			}
		}
		cout << factor << " ";
	}
}