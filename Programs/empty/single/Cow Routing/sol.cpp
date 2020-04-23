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
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
	lll a, b, n;
	cin >> a >> b >> n;
	lll minimum = INF;
	for (lll i = 0; i < n; i++)
	{
		lll cost;
		cin >> cost;
		lll num;
		cin >> num;
		bool got_a = 0;
		for (lll j = 0; j < num; j++)
		{
			lll temp;
			cin >> temp;
			if (temp == a)
			{
				got_a = 1;
			}
			if (got_a && temp == b)
			{
				minimum = min(minimum, cost);
			}
		}
	}
	if (minimum == INF)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << minimum << "\n";
	}
}