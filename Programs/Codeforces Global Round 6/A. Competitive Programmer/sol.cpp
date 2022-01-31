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
	while (n--)
	{
		string s;
		cin >> s;
		int three = 0;
		for (char i : s)
		{
			three += i - '0';
		}
		if (three % 3 != 0)
		{
			cout << "cyan\n";
			continue;
		}
		bool flag = true;
		for (char i : s)
		{
			if (i == '0')
			{
				flag = false;
				continue;
			}
		}
		if (flag)
		{
			cout << "cyan\n";
			continue;
		}
		int cnt = 0, other = 0;
		for (char i : s)
		{
			if (i == '0')
			{
				cnt++;
			}
			if (i == '2' || i == '4' || i == '6' || i == '8')
			{
				other++;
			}
		}
		if (cnt >= 2)
		{
			cout << "red\n";
			continue;
		}
		if (other >= 1 && cnt >= 1)
		{
			cout << "red\n";
			continue;
		}
		cout << "cyan\n";
	}
}