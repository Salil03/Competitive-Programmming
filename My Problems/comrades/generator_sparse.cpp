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
	int m = (2 * n * (2 * n - 1)) / 2;
	cout << 3 * n << " " << m << "\n";
	vector<pair<int, int>> edges_vector(edges.begin(), edges.end());
	shuffle(edges_vector.begin(), edges_vector.end());
	for (auto e : edges_vector)
	{
		cout << e.first << " " << e.second << "\n";
	}
}