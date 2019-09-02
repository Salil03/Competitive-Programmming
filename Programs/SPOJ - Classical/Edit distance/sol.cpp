#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

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
		string x, y;
		cin >> x >> y;
		int a = x.length(), b = y.length();
		int dp[a + 1][b + 1];
		dp[0][0] = 0;
		for (int i = 0; i <= a; i++)
		{
			for (int j = 0; j <= b; j++)
			{
				if (i == 0)
				{
					dp[i][j] = j;
				}
				else if (j == 0)
				{
					dp[i][j] = i;
				}
				else if (x[i - 1] == y[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
				}
			}
		}
		cout << dp[a][b] << "\n";
	}
}