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
	string s;
	cin >> s;
	int len = s.length();
	int prefix[len] = {0};
	if (s[0] == s[1])
	{
		prefix[0] = 1;
	}
	for (int i = 1; i < len; i++)
	{
		prefix[i] = prefix[i - 1];
		if (i == len - 1)
		{
			continue;
		}
		if (s[i] == s[i + 1])
		{
			prefix[i]++;
		}
	}
	int m;
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (s[x - 1] == s[x])
		{
			cout << prefix[y - 2] - prefix[x - 1] + 1 << "\n";
			continue;
		}
		cout << prefix[y - 2] - prefix[x - 1] << "\n";
	}
}