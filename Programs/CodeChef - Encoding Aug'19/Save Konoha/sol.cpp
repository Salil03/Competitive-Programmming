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
		int n, z;
		cin >> n >> z;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int cnt = 0;
		while (z > 0)
		{
			int i = max_element(arr, arr + n) - arr;
			if (arr[i] <= 0)
			{
				break;
			}
			z -= arr[i];
			arr[i] /= 2;
			cnt++;
		}
		if (z <= 0)
		{
			cout << cnt << "\n";
		}
		else
		{
			cout << "Evacuate\n";
		}
	}
}