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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int maximum = 0;
		int idx = 0;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'A')
			{
				idx = i;
				break;
			}
			if (i == n - 1)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			cout << 0 << "\n";
			continue;
		}
		int sum = 0;
		for (int i = idx + 1; i < n; i++)
		{
			if (s[i] == 'P')
			{
				sum++;
			}
			else
			{
				maximum = max(sum, maximum);
				sum = 0;
			}
		}
		cout << max(maximum, sum) << "\n";
	}
}