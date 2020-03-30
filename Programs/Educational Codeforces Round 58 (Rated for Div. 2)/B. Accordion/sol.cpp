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
	string s;
	cin >> s;
	int n = s.length();
	int first = -1, last = -1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '[')
		{
			first = i;
			break;
		}
	}
	if (first == -1)
	{
		cout << -1;
		return 0;
	}
	for (int i = n - 1; i > first; i--)
	{
		if (s[i] == ']')
		{
			last = i;
			break;
		}
	}
	if (last == -1)
	{
		cout << -1;
		return 0;
	}
	int semifirst = -1, semilast = -1;
	for (int i = first + 1; i < last; i++)
	{
		if (s[i] == ':')
		{
			semifirst = i;
			break;
		}
	}
	if (semifirst == -1)
	{
		cout << -1;
		return 0;
	}
	for (int i = last - 1; i > semifirst; i--)
	{
		if (s[i] == ':')
		{
			semilast = i;
			break;
		}
	}
	if (semilast == -1)
	{
		cout << -1;
		return 0;
	}
	int cnt = 0;
	for (int i = semifirst + 1; i < semilast; i++)
	{
		if (s[i] == '|')
		{
			cnt++;
		}
	}
	cout << cnt + 4;
}