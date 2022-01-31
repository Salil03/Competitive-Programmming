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
	int t;
	cin >> t;
	while (t--)
	{
		lll n, s;
		cin >> n >> s;
		lll arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		lll idx = 0, j = 0, maximum = 0;
		while (s >= 0 && j < n)
		{
			if (arr[j] > maximum)
			{
				if (idx != 0)
				{
					s -= arr[idx - 1];
				}
				maximum = arr[j];
				idx = j + 1;
			}
			else
			{
				s -= arr[j];
			}
			cout << s << "\n";
			j++;
		}
		if (s >= 0)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << idx << "\n";
		}
	}
}