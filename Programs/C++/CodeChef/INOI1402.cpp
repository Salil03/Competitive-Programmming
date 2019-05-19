#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

/*
$alil03

URL: https://www.codechef.com/INOIPRAC/problems/INOI1402

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int c, f;
	cin >> c >> f;
	long long int graph[c + 1][c + 1] = {{0}};
	for (long long int i = 0; i < f; i++)
	{
		long long int x, y, p;
		cin >> x >> y >> p;
		graph[x][y] = p;
		graph[y][x] = p;
	}
	long long int distance[c + 1][c + 1] = {{0}};
	for (long long int i = 1; i <= c; i++)
	{
		for (long long int j = 1; j <= c; j++)
		{
			if (i == j)
			{
				distance[i][j] = 0;
			}
			else if (graph[i][j])
			{
				distance[i][j] = graph[i][j];
			}
			else
			{
				distance[i][j] = INF;
			}
		}
	}
	for (long long int k = 1; k <= c; k++)
	{
		for (long long int i = 1; i <= c; i++)
		{
			for (long long int j = 1; j <= c; j++)
			{
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}
	long long int maximum = INT_MIN;
	for (long long int i = 1; i <= c; i++)
	{
		for (long long int j = 1; j <= c; j++)
		{
			maximum = max(maximum, distance[i][j]);
		}
	}
	cout << maximum;
}