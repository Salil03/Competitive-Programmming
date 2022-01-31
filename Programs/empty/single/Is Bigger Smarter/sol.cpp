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
vector<lll> ans;
void recur(lll node, lll parent, pair<lll, lll> dp[])
{
	if (node == parent || node == 0)
	{
		return;
	}
	ans.push_back(node + 1);
	recur(dp[node].second, node, dp);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<lll> w, s;
	lll x, y;
	while (cin >> x)
	{
		cin >> y;
		w.push_back(x);
		s.push_back(y);
	}
	pair<lll, lll> dp[w.size()];
	dp[0].first = 1;
	dp[0].second = 0;
	lll n = w.size();
	for (lll i = 1; i < n; i++)
	{
		dp[i].first = 1;
		dp[i].second = i;
		for (lll j = i - 1; j >= 0; j--)
		{
			if (w[j] < w[i] && s[j] > s[i])
			{
				if (dp[i].first < dp[j].first + 1)
				{
					dp[i].first = dp[j].first + 1;
					dp[i].second = j;
				}
			}
		}
	}
	lll maximum = 1, idx = 0;
	for (lll i = 0; i < n; i++)
	{
		if (dp[i].first > maximum)
		{
			maximum = dp[i].first;
			idx = i;
		}
	}
	cout << maximum << "\n";
	recur(idx, -1, dp);
	reverse(ans.begin(), ans.end());
	for (lll i : ans)
	{
		cout << i << "\n";
	}
}