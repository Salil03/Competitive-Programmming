#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void checkAns(InStream &stream, int n, vector<vector<bool>> &graph)
{
	vector<int> clique = stream.readInts(n, 1, 3 * n, "friends index");
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (clique[i] == clique[j] || !(graph[clique[i]][clique[j]] && graph[clique[i]][clique[j]]))
			{
				stream.quitf(_wa, "Friend %d and friend %d do not have a connection", clique[i], clique[j]);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// This command initializes checker environment.
	registerTestlibCmd(argc, argv);
	int n = inf.readInt() / 3;
	int m = inf.readInt();
	vector<vector<bool>> graph(3 * n + 1, vector<bool>(3 * n + 1, false));
	for (int i = 0; i < m; i++)
	{
		int u = inf.readInt();
		int v = inf.readInt();
		graph[u][v] = true;
		graph[v][u] = true;
	}
	checkAns(ans, n, graph);
	checkAns(ouf, n, graph);
	quitf(_ok, "Alliance of size %d is correct", n);
}