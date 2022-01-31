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
const lll INF = 1000000000000000;

/*
$alil03

URL: url

Solution Begins here
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int N, M;
		cin >> N >> M;

		lll C[N + 1] = {0};
		pair<lll, lll> P[M + 1] = {{0, 0}};

		for (int x = 1; x <= N; x++)
			cin >> C[x];

		for (int x = 1; x <= M; x++)
			cin >> P[x].second;

		for (int x = 1; x <= M; x++)
			cin >> P[x].first;

		sort(P, P + M + 1);

		ll DP[N + 1][M + 1] = {};

		DP[0][0] = 0;
		for (int n = 0; n <= N; n++)
		{
			for (int m = 0; m <= M; m++)
			{
				if (n or m)
					DP[n][m] = INF;
				if (m)
				{
					ll Cost;
					if (DP[n][m - 1] > P[m].first)
						Cost = INF;
					else if (DP[n][m - 1] + P[m].second < P[m].first)
						Cost = P[m].first;
					else
						Cost = DP[n][m - 1] + P[m].second;

					DP[n][m] = Cost;
				}
				if (n)
				{
					DP[n][m] = min(DP[n][m], DP[n - 1][m] + C[n]);
				}
			}
		}
		if (DP[N][M] == INF)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << DP[N][M] << "\n";
		}
	}
}