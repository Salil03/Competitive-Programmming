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

long long int money, stalls, cows;

long long int recur(long long int idx, bool cover, bool arr[], long long int m)
{
	if (idx == stalls)
	{
		return 0;
	}
	if (m == 0)
	{
		return INT_MAX;
	}
	if (arr[idx])
	{
		return min(recur(idx + 1, 1, arr, m) + 1, recur(idx + 1, 0, arr, m - 1) + 1);
	}
	else
	{
		if (cover)
		{
			return min(recur(idx + 1, 1, arr, m) + 1, recur(idx + 1, 0, arr, m - 1));
		}
		else
		{
			return recur(idx + 1, 0, arr, m);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> money >> stalls >> cows;
	bool arr[stalls] = {0};
	for (long long int i = 0; i < cows; i++)
	{
		long long int temp;
		cin >> temp;
		arr[temp - 1] = 1;
	}
	cout << recur(0, 0, arr, money);
}