#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define dbga(x, n) cerr << "\n" \
						<< (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
					<< (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution < lll>(low, high)(rng)
// uniform_real_distribution<double>(low, high)(rng)

typedef tree<lll, null_type, less<lll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<lll, lll>, null_type, less<pair<lll, lll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// gp_hash_table<int, int> table; unordered map

#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// freopen("file.in", "r", stdin);
	// freopen("file.out", "w", stdout);
	lll n, m;
	cin >> n >> m;
	lll start, end;
	cin >> start >> end;
	lll table[n + 1][2][2] = {0}; // idx, k, bool
	for (lll idx = 1; idx <= n; idx++)
	{
		for (lll mass = 0; mass <= 1; mass++)
		{
			if (idx == start && mass == 0)
			{
				table[idx][0][mass] = 1;
			}
			else
			{
				table[idx][0][mass] = 0;
			}
			table[idx][1][mass] = 0;
		}
	}
	for (lll k = 1; k <= m; k++)
	{
		for (lll idx = 1; idx <= n; idx++)
		{
			for (lll city = 1; city <= n; city++)
			{
				table[idx][1][0] = (table[idx][1][0] + table[city][0][0]) % MOD;
				table[idx][1][1] = (table[idx][1][1] + table[city][0][1]) % MOD;
				if (gcd(idx, city) == 1)
				{
					table[idx][1][0] = (table[idx][1][0] + table[city][0][1]) % MOD;
					table[idx][1][1] = (table[idx][1][1] + table[city][0][0]) % MOD;
				}
			}
		}
		for (lll idx = 1; idx <= n; idx++)
		{
			table[idx][0][0] = table[idx][1][0];
			table[idx][0][1] = table[idx][1][1];
			table[idx][1][0] = 0;
			table[idx][1][1] = 0;
		}
	}
	cout << table[end][0][1] % MOD << "\n";
}