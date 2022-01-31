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
long long int n;
long long int dp[100010][2] = {};
long long int recur(long long int idx, bool rev, long long int arr[], string lex[])
{
	if (idx == n)
	{
		return 0;
	}
	if (dp[idx][rev] != -1)
	{
		return dp[idx][rev];
	}
	if (rev)
	{
		long long int ans = INF;
		if (!lexicographical_compare(lex[idx].begin(), lex[idx].end(), lex[idx - 1].rbegin(), lex[idx - 1].rend()))
		{
			ans = min(ans, recur(idx + 1, 0, arr, lex));
		}
		if (!lexicographical_compare(lex[idx].rbegin(), lex[idx].rend(), lex[idx - 1].rbegin(), lex[idx - 1].rend()))
		{
			ans = min(ans, arr[idx] + recur(idx + 1, 1, arr, lex));
		}
		return dp[idx][rev] = ans;
	}
	if (!rev)
	{
		long long int ans = INF;
		if (!lexicographical_compare(lex[idx].begin(), lex[idx].end(), lex[idx - 1].begin(), lex[idx - 1].end()))
		{
			ans = min(ans, recur(idx + 1, 0, arr, lex));
		}
		if (!lexicographical_compare(lex[idx].rbegin(), lex[idx].rend(), lex[idx - 1].begin(), lex[idx - 1].end()))
		{
			ans = min(ans, arr[idx] + recur(idx + 1, 1, arr, lex));
		}
		return dp[idx][rev] = ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	long long int arr[n];
	for (long long int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	string lex[n];
	for (long long int i = 0; i < n; i++)
	{
		cin >> lex[i];
	}
	for (int i = 0; i < n + 4; i++)
	{
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	if (min(recur(1, 0, arr, lex), arr[0] + recur(1, 1, arr, lex)) < INF)
	{
		cout << min(recur(1, 0, arr, lex), arr[0] + recur(1, 1, arr, lex));
	}
	else
	{
		cout << -1;
	}
}