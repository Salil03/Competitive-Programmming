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
	vector<int> v, c;
	int S, N;
	cin >> S >> N;

	// sloted for easy array access; values won't be used.
	c.push_back(-1);
	v.push_back(-1);

	int ct, vt;
	for (int i = 0; i < N; i++)
	{
		cin >> ct >> vt;
		c.push_back(ct);
		v.push_back(vt);
	}

	vector<vector<int>> DP(N + 1, vector<int>(S + 1, 0));

	for (int i = 1; i <= N; i++)
	{ // i is scope of items in consideration
		for (int w = 1; w <= S; w++)
		{ // j is max size of bag
			if (c[i] > w)
			{
				DP[i][w] = DP[i - 1][w];
			}
			else
			{
				DP[i][w] = max(DP[i - 1][w], v[i] + DP[i - 1][w - c[i]]);
			}
		}
	}

	cout << DP[N][S];
}