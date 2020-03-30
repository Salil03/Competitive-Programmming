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

bool check(lll arr[], lll x, lll c, lll n)
{
	int cnt = c - 1, index = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - arr[index] >= x)
		{
			cnt--;
			index = i;
		}
	}
	return (cnt <= 0);
}

int main()
{
	lll t;
	cin >> t;
	while (t--)
	{
		lll n, c;
		cin >> n >> c;
		lll arr[n];
		for (lll i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		lll high = *max_element(arr, arr + n) + 1;
		lll low = 0;
		int med = (high + low) / 2;
		while (low <= high)
		{
			if (check(arr, med, c, n))
			{
				low = med + 1;
				med = (high + low) / 2;
			}
			else
			{
				high = med - 1;
				med = (high + low) / 2;
			}
		}
		cout << med << "\n";
	}
}