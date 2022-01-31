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
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

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
	long long int n;
	long long int w;
	long long int l;
	cin >> n;
	cin >> w;
	cin >> l;
	long long int h[n];
	long long int r[n];
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
		cin >> r[i];
	}
	long long int lo = -1;
	long long int high = 1000000000000000000;
	long long int mid;
	while (high - lo > 1)
	{
		mid = (high + lo) / (2);
		long long int wood = 0;
		for (int i = 0; i < n; i++)
		{
			if (h[i] + mid * r[i] >= l)
			{
				wood += h[i] + (mid) * (r[i]);
			}
			if (wood >= w)
			{
				break;
			}
		}
		if (wood >= w)
		{
			high = mid;
		}
		else
		{
			lo = mid;
		}
	}
	cout << high;
}