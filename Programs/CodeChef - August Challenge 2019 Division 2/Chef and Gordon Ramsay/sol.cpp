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
		int n;
		cin >> n;
		int p1, p2, p3;
		cin >> p1 >> p2 >> p3;
		vector<int> graph[n];
		int cent = -1;
		for (int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[x - 1].push_back(y);
			graph[y - 1].push_back(x);
		}
		for (int i = 0; i < n; i++)
		{
			if (graph[i].size() > 1)
			{
				cent = i;
				break;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (i == cent)
			{
				continue;
			}
			for (int j = 0; j < n; j++)
			{
				if (j == i || j == cent)
				{
					continue;
				}
				if (p1 > p2)
				{
					if (i < cent)
					{
						continue;
					}
				}
				if (p1 > p3)
				{
					if (i < j)
					{
						continue;
					}
				}
				if (p2 > p1)
				{
					if (cent < i)
					{
						continue;
					}
				}
				if (p2 > p3)
				{
					if (cent < j)
					{
						continue;
					}
				}
				if (p3 > p1)
				{
					if (j < i)
					{
						continue;
					}
				}
				if (p3 > p2)
				{
					if (j < cent)
					{
						continue;
					}
				}
				ans++;
			}
		}
		cout << ans << '\n';
	}
}