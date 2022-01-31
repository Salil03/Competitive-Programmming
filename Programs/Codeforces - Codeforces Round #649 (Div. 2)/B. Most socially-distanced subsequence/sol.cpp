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
	lll t;
	cin >> t;
	lll cnt = 0;
	for (int i = 0; i < t; i++)
	{
		lll n;
		cin >> n;
		lll m = n;
		lll a[n];
		lll answer[n] = {0};
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		for (int k = 0; k <= n; k++)
		{
			cnt = 0;
			cout << k << "try"
				 << "\n";
			for (int j = 0; j < n; j++)
			{
				cout << a[j] << " ";
			}
			cout << "\n";
			lll d[n - 1];
			for (int j = 0; j < n; j++)
			{
				answer[j] = -1;
			}
			for (int j = 0; j < n - 1; j++)
			{
				d[j] = a[j + 1] - a[j];
			}
			answer[0] = a[0];
			cnt = 1;
			for (int j = 0; j < n - 2; j++)
			{
				if (d[j + 1] * d[j] < 0)
				{

					answer[cnt] = a[j + 1];
					cnt++;
					answer[cnt] = a[j + 2];
					cnt++;
				}
			}
			if (answer[cnt - 1] != a[n - 1])
			{
				answer[cnt] = a[n - 1];
				cnt++;
			}
			n = cnt;
			for (int j = 0; j < n; j++)
			{
				a[j] = answer[j];
			}
		}

		cout << cnt << "\n";
		for (int j = 0; j < cnt; j++)
		{
			cout << answer[j] << " ";
		}
		cout << "\n";
	}
}