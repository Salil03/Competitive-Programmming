#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/MAY19B/problems/MATCHS

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
		int n, m;
		cin >> n >> m;
		bool ari = true;
		while (n != 1 && m != 1)
		{
			if (ari)
			{
				for (int i = n; i >= m; i--)
				{
					if (m % i == 0)
					{
						n -= i;
						break;
					}
				}
				ari = false;
			}
			else
			{
				for (int i = n; i >= m; i--)
				{
					if (m % i == 0)
					{
						n -= i;
						break;
					}
				}
				ari = false;
			}
		}
	}
}