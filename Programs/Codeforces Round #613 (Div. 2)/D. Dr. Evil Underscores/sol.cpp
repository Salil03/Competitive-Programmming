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

int main()
{
	lll n;
	cin >> n;
	lll arr[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	lll itr = *max_element(arr, arr + n);
	lll p = log2(itr) + 1;
	lll X = 0;
	for (lll i = 0; i < p; i++)
	{
		lll count = 0;
		for (lll j = 0; j < n; j++)
		{
			if (arr[j] & (1 << i))
			{
				count++;
			}
		}
		if (count > (n / 2))
		{
			X += 1 << i;
		}
	}

	lll sum = 0;
	for (lll i = 0; i < n; i++)
		sum += (X ^ arr[i]);

	cout << X << " " << sum;
}