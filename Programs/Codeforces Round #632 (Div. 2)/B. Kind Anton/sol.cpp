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
	for (int i = 0; i < t; i++)
	{
		lll n;
		cin >> n;
		lll a[n + 1] = {0};
		lll b[n + 1] = {0};
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		for (int j = 0; j < n; j++)
		{
			cin >> b[j];
		}
		lll fo = n + 5;
		lll fmo = n + 5;
		lll o = n + 5;

		for (int j = 0; j < n; j++)
		{
			if (a[j] == 1)
			{
				fo = j;
				break;
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (a[j] == -1)
			{
				fmo = j;
				break;
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (a[j] == 0)
			{
				o = j;
				break;
			}
		}
		int flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (b[j] == 0)
			{
				if ((!(a[j] == 0) || ((j >= fo) && (j >= fmo))))
				{
					flag = 1;
					break;
				}
			}
			if (b[j] > 0)
			{
				if (!((j > fo) || (a[j] == b[j]) || ((j == fo) && (o < j))))
				{
					flag = 1;
					break;
				}
			}
			if (b[j] < 0)
			{
				if (!((j < fo) || (a[j] == b[j]) || ((j == fmo) && (o < j))))
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)
		{
			cout << "NO"
				 << "\n";
		}
		else
		{
			cout << "YES"
				 << "\n";
		}
	}
}
