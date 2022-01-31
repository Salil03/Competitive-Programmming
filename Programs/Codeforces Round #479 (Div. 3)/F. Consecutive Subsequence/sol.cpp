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
	lll n;
	cin >> n;
	lll arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	map<lll, lll> dp;
	lll maximum = 1;
	lll index = 0;
	dp[arr[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[arr[i]] = dp[arr[i] - 1] + 1;
		if (maximum < dp[arr[i]])
		{
			maximum = dp[arr[i]];
			index = i;
		}
	}
	cout << maximum << "\n";
	lll final[maximum] = {0};
	final[maximum - 1] = index;
	lll curr = maximum - 2;
	for (int i = index - 1; i >= 0; i--)
	{
		if (arr[i] == arr[index] - 1)
		{
			final[curr] = i;
			curr--;
			index = i;
		}
	}
	for (lll i : final)
	{
		cout << i + 1 << " ";
	}
}