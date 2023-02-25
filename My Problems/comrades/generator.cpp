#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	registerGen(argc, argv, 1);
	// 	int min_n = atoi(argv[1]);
	// 	int max_n = atoi(argv[2]);
	// 	int n = rnd.next(min_n, max_n);
	int n = atoi(argv[1]);
	vector<int> people(3 * n);
	for (int i = 0; i < 3 * n; i++)
	{
		people[i] = i + 1;
	}
	shuffle(people.begin(), people.end());
	set<pair<int, int>> edges;
	for (int i = 0; i < 2 * n; i++)
	{
		for (int j = i + 1; j < 2 * n; j++)
		{
			edges.insert(make_pair(people[i], people[j]));
		}
	}
	int m = rnd.next((2 * n * (2 * n - 1)) / 2, (3 * n * (3 * n - 1)) / 2);
	for (int i = (2 * n * (2 * n - 1)) / 2; i < m; i++)
	{
		int u = rnd.any(people), v = rnd.any(people);
		while (edges.find(make_pair(u, v)) != edges.end() || edges.find(make_pair(v, u)) != edges.end() || u == v)
		{
			u = rnd.any(people);
			v = rnd.any(people);
		}
		edges.insert(make_pair(u, v));
	}
	cout << 3 * n << " " << m << "\n";
	vector<pair<int, int>> edges_vector(edges.begin(), edges.end());
	shuffle(edges_vector.begin(), edges_vector.end());
	for (auto e : edges_vector)
	{
		cout << e.first << " " << e.second << "\n";
	}
}