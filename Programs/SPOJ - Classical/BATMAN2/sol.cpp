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

int table[110][110][110];

int dp(int idx, int maxi, int mini, int arr[], int n)
{
	if (idx == n)
	{
		return 0;
	}
	if (table[idx][maxi][mini] != -1)
	{
		return table[idx][maxi][mini];
	}
	int ans = -1;
	if (arr[idx] > arr[maxi] || maxi == n - 1)
	{
		ans = max(ans, 1 + dp(idx + 1, idx, mini, arr, n));
	}
	if (arr[idx] < arr[mini] || mini == n - 1)
	{
		ans = max(ans, 1 + dp(idx + 1, maxi, idx, arr, n));
	}
	ans = max(ans, dp(idx + 1, maxi, mini, arr, n));
	return table[idx][maxi][mini] = ans;
}

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
		memset(table, -1, sizeof table);
		cout << dp(0, n - 1, n - 1, arr, n) << "\n";
	}
}