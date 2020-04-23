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
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		vector<int> graph[n + 1];
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (gcd(arr[i], arr[j]) == 1)
				{
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		int colours[n][n] = {0};
		memset(colours, -1, sizeof(colours));
		for (int i = 0; i < n; i++)
		{
			colours[i][i] = 1;
			bool avail[n] = {0};
			for (int u = 0; u < n; u++)
			{
				if (u == i)
				{
					continue;
				}
				for (int node : graph[u])
				{
					if (colours[i][node] != -1)
					{
						avail[colours[i][node]] = 1;
					}
				}
				int cool;
				for (cool = 0; cool < n; cool++)
				{
					if (!avail[cool])
					{
						break;
					}
				}
				colours[i][u] = cool;
				for (int node : graph[u])
				{
					if (colours[i][node] != -1)
					{
						avail[colours[i][node]] = 0;
					}
				}
			}
		}
		int minimum = INT_MAX, idx = 0;

		for (int j = 0; j < n; j++)
		{
			if (minimum > *max_element(colours[j], colours[j] + n))
			{
				minimum = *max_element(colours[j], colours[j] + n);
				idx = j;
			}
		}
		cout << minimum + 1 << "\n";
		for (int i = 0; i < n; i++)
		{
			if (i == idx)
			{
				cout << 1 << " ";
				continue;
			}
			cout << colours[idx][i] + 1 << " ";
		}
		cout << "\n";
	}
}