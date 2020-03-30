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
double final[17][17];
int n;
map<pair<int, int>, double> table;
double dp(int idx, int mask)
{
	if (idx == 2 * n)
	{
		return 0;
	}
	double minimum = INT_MAX;
	if (table.find({idx, mask}) != table.end())
	{
		return table[{idx, mask}];
	}
	if (mask & (1 << idx))
	{
		return table[{idx, mask}] = dp(idx + 1, mask);
	}
	for (int i = 0; i < 2 * n; i++)
	{
		if (i == idx)
		{
			continue;
		}
		if (!(mask & (1 << i)))
		{
			minimum = min(minimum, final[i][idx] + dp(idx + 1, mask | (1 << i) | (1 << idx)));
		}
	}
	return table[{idx, mask}] = minimum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 0;
	while (cin >> n)
	{
		t++;
		if (n == 0)
		{
			return 0;
		}
		pair<double, double> arr[2 * n];
		for (int i = 0; i < 2 * n; i++)
		{
			string s;
			cin >> s;
			cin >> arr[i].first >> arr[i].second;
		}
		for (int i = 0; i < 2 * n; i++)
		{
			for (int j = 0; j < 2 * n; j++)
			{
				if (i == j)
				{
					final[i][i] = 0;
				}
				else
				{
					final[i][j] = sqrt((arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second));
				}
			}
		}
		table.clear();
		cout
			<< fixed << setprecision(2) << "Case " << t << ": " << dp(0, 0) << "\n";
	}
}