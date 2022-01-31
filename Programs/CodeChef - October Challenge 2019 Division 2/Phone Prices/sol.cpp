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
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int cnt = 1;
		for (int i = 1; i < n; i++)
		{
			bool flag = true;
			for (int j = i - 1; j >= 0 && j >= i - 5; j--)
			{
				if (arr[i] >= arr[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}