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
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int g[n + 1] = {};
		for (int i = 0; i <= n; i++)
		{
			cin >> g[i];
		}
		int b[n] = {};
		int right = n;
		for (int i = 0; i < n; i++)
		{
			while (g[right] == 0 && right > 0)
			{
				watch(right);
				right--;
			}
			b[i] = right;
			g[right]--;
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] != -1)
			{
				b[a[i]]--;
			}
		}
		int curr = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != -1)
			{
				cout << a[i] << " ";
				continue;
			}
			while (b[curr] == 0)
			{
				curr++;
			}
			for (int j = 0; j < b[curr]; j++)
			{
				cout << curr << " ";
			}
			curr++;
		}
		cout << "\n";
	}
}