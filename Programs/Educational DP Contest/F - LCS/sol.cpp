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
string a, b;
int table[3004][3004] = {{0}};
int dp(int x, int y)
{
	if (table[x][y] != -1)
	{
		return table[x][y];
	}
	if (a[x - 1] == b[y - 1])
	{
		return table[x][y] = 1 + dp(x - 1, y - 1);
	}
	else
	{
		return table[x][y] = max(dp(x - 1, y), dp(x, y - 1));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	int len1 = a.length(), len2 = b.length();
	for (int i = 0; i <= len1; i++)
	{
		table[i][0] = 0;
	}
	for (int i = 0; i <= len2; i++)
	{
		table[0][i] = 0;
	}
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			table[i][j] = -1;
		}
	}
	dp(len1, len2);
	int i = len1, j = len2;
	string final;
	while (true)
	{
		if (i == 0 || j == 0)
		{
			break;
		}
		if (a[i - 1] == b[j - 1])
		{
			final += a[i - 1];
			i--;
			j--;
		}
		else
		{
			if (max({table[i - 1][j - 1], table[i - 1][j], table[i][j - 1]}) == table[i - 1][j - 1])
			{
				i--;
				j--;
			}
			else if (max({table[i - 1][j - 1], table[i - 1][j], table[i][j - 1]}) == table[i - 1][j])
			{
				i--;
			}
			else if (max({table[i - 1][j - 1], table[i - 1][j], table[i][j - 1]}) == table[i][j - 1])
			{
				j--;
			}
		}
	}
	reverse(final.begin(), final.end());
	cout << final;
}