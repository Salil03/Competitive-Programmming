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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int table[3][5010] = {};
	for (int j = 0; j < n; j++)
	{
		table[0][j] = table[1][j] = 0;
	}
	for (int len = 2; len <= n; len++)
	{
		for (int l = 0; l + len - 1 < n; l++)
		{
			if (s[l] == s[len + l - 1])
			{
				table[2][l] = table[0][l + 1];
			}
			else if (s[l] != s[len + l - 1])
			{
				table[2][l] = min(table[1][l + 1], table[1][l]) + 1;
			}
		}
		swap(table[1], table[0]);
		swap(table[1], table[2]);
	}
	cout << table[1][0];
}