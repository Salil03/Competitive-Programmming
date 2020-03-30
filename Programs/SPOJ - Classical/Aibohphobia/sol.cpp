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

int dp(int left, int right, string s)
{
	if (left == right)
	{
		return 0;
	}
	if (left == right - 1)
	{
		if (s[left] == s[right])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (s[left] == s[right])
	{
		return dp(left + 1, right - 1, s);
	}
	else
	{
		return 1 + min(dp(left + 1, right, s), dp(left, right - 1, s));
	}
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
		string s;
		cin >> s;
		string temp = s;
		reverse(temp.begin(), temp.end());
		if (temp == s)
		{
			cout << 0 << "\n";
			continue;
		}
		int len = s.length();
		cout << dp(0, len - 1, s) << "\n";
	}
}