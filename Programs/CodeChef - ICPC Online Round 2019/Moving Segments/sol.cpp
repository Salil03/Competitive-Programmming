//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
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
		int arr[n][3];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		}
		int cnt[n] = {0};
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i][2] == arr[j][2])
				{
					if (arr[i][1] >= arr[j][0] and arr[j][1] >= arr[i][0])
					{
						cnt[i]++;
						cnt[j]++;
						cout << i << " " << j << "\n";
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << cnt[i] << "\n";
		}
		if (*max_element(cnt, cnt + n) >= 3)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
}