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

int table[300];

int dp(int idx, vector<int> arr[])
{
	if (idx == 0)
	{
		return 0;
	}
	if (table[idx] != -1)
	{
		return table[idx];
	}
	int ans = 1 + dp(idx - 1, arr);
	for (int i : arr[idx])
	{
		ans = min(ans, 1 + dp(i, arr));
	}
	return table[idx] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, p;
	cin >> n >> p;
	vector<int> arr[n];
	for (int i = 0; i < p; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[y].push_back(x);
	}
	memset(table, -1, sizeof table);
	cout << dp(n - 1, arr);
}