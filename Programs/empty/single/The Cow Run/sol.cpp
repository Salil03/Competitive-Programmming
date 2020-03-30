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

int dp(int idx, int left, int right, int arr[], int n)
{
	if (left == 0 && right == n)
	{
		return 0;
	}
	if (idx == n)
	{
		return dp(left, left, n, arr, n);
	}
	if (idx == 0)
	{
		return dp(right, 0, right, arr, n);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	arr[n] = 0;
	sort(arr, arr + n + 1);
	int start = lower_bound(arr, arr + n + 1, 0) - arr;
}