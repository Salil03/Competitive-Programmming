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
set<char> final;
void dp(int green, int blue, int red)
{
	if (red == 0 && green == 0)
	{
		final.insert('B');
	}
	if (red == 0 && blue == 0)
	{
		final.insert('G');
	}
	if (green == 0 && blue == 0)
	{
		final.insert('R');
	}
	if (red > 1)
	{
		dp(green, blue, red - 1);
	}
	if (green > 1)
	{
		dp(green - 1, blue, red);
	}
	if (blue > 1)
	{
		dp(green, blue - 1, red);
	}
	if (red > 0 && blue > 0)
	{
		dp(green + 1, blue - 1, red - 1);
	}
	if (red > 0 && green > 0)
	{
		dp(green - 1, blue + 1, red - 1);
	}
	if (green > 0 && blue > 0)
	{
		dp(green - 1, blue - 1, red + 1);
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int g = 0, b = 0, r = 0;
	for (char i : s)
	{
		if (i == 'G')
		{
			g++;
		}
		if (i == 'R')
		{
			r++;
		}
		if (i == 'B')
		{
			b++;
		}
	}
	dp(g, b, r);
	for (char i : final)
	{
		cout << i;
	}
}