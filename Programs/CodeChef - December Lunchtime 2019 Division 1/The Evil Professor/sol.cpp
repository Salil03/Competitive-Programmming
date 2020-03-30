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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		lll n = s.length();
		lll ans = 0;
		lll prefix[n] = {};
		prefix[0] = s[0] == s[1];
		for (int i = 1; i < n - 1; i++)
		{
			prefix[i] = prefix[i - 1];
			if (s[i] == s[i + 1])
			{
				prefix[i]++;
			}
		}
		prefix[n - 1] = prefix[max(n - 2, 0LL)];
		lll prefix2[n] = {};
		prefix2[0] = prefix[0];
		for (int i = 1; i < n; i++)
		{
			prefix2[i] = prefix2[i - 1] + prefix[i];
		}
		cout << "\n";
		for (int i = 0; i < n; i++)
		{
			ans += prefix2[i];
		}
		cout << ans << "\n";
	}
}