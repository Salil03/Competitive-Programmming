//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

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
		lll arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		lll ans = 0;
		sort(arr, arr + 3);
		ans += arr[0];
		arr[2] -= arr[0];
		arr[0] = 0;
		sort(arr, arr + 3);
		if (arr[1] > 2)
		{
			ans += arr[1];
			arr[2] -= arr[1];
			arr[1] = 0;
			if (arr[2] > 2)
			{
				ans += arr[2];
			}
		}
		else
		{
			if (arr[2] > 2)
			{
				ans += arr[2];
			}
		}

		cout << ans << "\n";
	}
}