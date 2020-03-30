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
	lll n, p, q, r;
	cin >> n >> p >> q >> r;
	lll arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	lll min_prefix[n] = {};
	lll max_prefix[n] = {};
	lll min_suffix[n] = {};
	lll max_suffix[n] = {};
	min_prefix[0] = arr[0];
	max_prefix[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		min_prefix[i] = min(min_prefix[i - 1], arr[i]);
		max_prefix[i] = max(max_prefix[i - 1], arr[i]);
	}
	min_suffix[n - 1] = arr[n - 1];
	max_suffix[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		min_suffix[i] = min(min_suffix[i + 1], arr[i]);
		max_suffix[i] = max(max_suffix[i + 1], arr[i]);
	}
	lll ans = LLONG_MIN;
	for (int j = 0; j < n; j++)
	{
		lll sum = arr[j] * q;
		if (p < 0)
		{
			sum += min_prefix[j] * p;
		}
		else
		{
			sum += max_prefix[j] * p;
		}
		if (r < 0)
		{
			sum += min_suffix[j] * r;
		}
		else
		{
			sum += max_suffix[j] * r;
		}
		ans = max(ans, sum);
	}
	cout << ans;
}