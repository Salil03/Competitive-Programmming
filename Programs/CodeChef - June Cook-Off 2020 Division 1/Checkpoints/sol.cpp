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
	lll t;
	cin >> t;
	while (t--)
	{
		lll n, c;
		cin >> n >> c;
		pair<lll, lll> points[n];
		map<lll, vector<lll>> diagonals;
		for (lll i = 0; i < n; i++)
		{
			cin >> points[i].first >> points[i].second;
			diagonals[points[i].second - points[i].first].push_back(i);
		}
		lll cnt = 0;
		lll sum = 0;
		for (auto i : diagonals)
		{
			vector<lll> diff[c] = {{}};
			for (auto j : i.second)
			{
				lll x = points[j].first;
				lll y = points[j].second;
				diff[x % c].push_back(x);
			}
			for (auto j : diff)
			{
				if (!j.empty())
				{
					cnt++;
					sort(j.begin(), j.end());
					lll len = j.size();
					for (lll k : j)
					{
						sum += abs(k - j[len / 2]) / c;
					}
				}
			}
		}
		cout << cnt << " " << sum << "\n";
	}
}