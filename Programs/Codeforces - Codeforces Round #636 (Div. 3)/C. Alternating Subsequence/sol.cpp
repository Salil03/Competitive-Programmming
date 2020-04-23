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
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

lll sum_range(lll n, lll a[], int first, int second)
{
	lll ret = a[first];
	for (int k = first; k <= second; k++)
	{
		if (ret < a[k])
		{
			ret = a[k];
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		lll n;
		cin >> n;
		lll a[n];
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		lll max_length = 1;
		lll brk[n + 2] = {0};
		int itr = 1;
		brk[0] = 0;
		for (int j = 0; j < (n - 1); j++)
		{
			if (((a[j + 1] > 0) && (a[j] < 0)) || ((a[j + 1] < 0) && (a[j] > 0)))
			{
				brk[itr] = j + 1;
				itr++;
				max_length++;
			}
		}
		brk[itr] = n;
		lll r = 0;
		for (int j = 0; j < itr; j++)
		{
			r = r + sum_range(n, a, brk[j], (brk[j + 1]) - 1);
		}
		cout << r << "\n";
	}
}