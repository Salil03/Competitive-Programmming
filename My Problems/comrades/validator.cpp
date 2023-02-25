#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	registerValidation(argc, argv);
	int n = inf.readInt(1, 3'000, "3n");
	ensuref(n % 3 == 0, "3n is not divisible by 3");
	n /= 3;
	inf.readSpace();
	int m = inf.readInt((2 * n * (2 * n - 1)) / 2, (3 * n * (3 * n - 1)) / 2, "m");
	inf.readEoln();
	vector<vector<bool>> graph(3 * n + 1, vector<bool>(3 * n + 1, false));
	for (int i = 0; i < m; i++)
	{
		int u = inf.readInt(1, 3 * n, "u");
		inf.readSpace();
		int v = inf.readInt(1, 3 * n, "v");
		ensuref(u != v, "connection between %d and %d not valid", u, v);
		ensuref(!graph[u][v] && !graph[v][u], "connection between %d and %d already exists", u, v);
		graph[u][v] = true;
		graph[v][u] = true;
		inf.readEoln();
	}
	inf.readEof();
}