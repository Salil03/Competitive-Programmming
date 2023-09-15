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
	lll x, y;
	cin >> x >> y;
	vector<vector<lll>> distinct_primes(n + 1, vector<lll>());
	vector<vector<lll>> divisors(n + 1, vector<lll>());
	for (lll i = 1; i <= n; i++)
	{
		lll k = i;
		for (lll j = 2; j * j <= k; j++)
		{
			if (k % j == 0)
			{
				distinct_primes[i].emplace_back(j);
			}
			while (k % j == 0)
			{
				k /= j;
			}
		}
		if (k >= 2)
		{
			distinct_primes[i].emplace_back(k);
		}
	}
	for (lll i = 1; i <= n; i++)
	{
		lll j;
		for (j = 1; j * j < i; j++)
		{
			if (i % j == 0)
			{
				divisors[i].emplace_back(j);
			}
		}
		if (j - (i / j) == 1)
		{
			j--;
		}
		for (; j >= 1; j--)
		{
			if (i % j == 0)
			{
				divisors[i].emplace_back(i / j);
			}
		}
	}
	lll dp[n + 1][2][2] = {0};
	lll dp_sum[n + 1][2][2] = {0};
	for (lll idx = 1; idx <= n; idx++)
	{
		for (lll mass = 0; mass <= 1; mass++)
		{
			if (idx == x && mass == 0)
			{
				dp[idx][0][mass] = 1;
			}
			else
			{
				dp[idx][0][mass] = 0;
			}
			dp[idx][1][mass] = 0;
			dp_sum[idx][0][mass] = 0;
			dp_sum[idx][1][mass] = 0;
		}
	}
	for (auto divisor : divisors[x])
	{
		dp_sum[divisor][0][0] = 1;
	}
	for (lll k = 1; k <= m; k++)
	{
		for (lll idx = 1; idx <= n; idx++)
		{
			dp[idx][1][0] = dp_sum[1][0][0];
			dp[idx][1][1] = dp_sum[1][0][1];
			lll num = (1 << distinct_primes[idx].size());
			for (lll i = 0; i < num; i++)
			{
				lll cnt = 0;
				lll prod = 1;
				for (lll j = 0; j < (lll)distinct_primes[idx].size(); j++)
				{
					if (i & (1 << j))
					{
						cnt++;
						prod *= distinct_primes[idx][j];
					}
				}
				if (cnt & 1)
				{
					dp[idx][1][0] = (dp[idx][1][0] - dp_sum[prod][0][1]) % MOD;
					dp[idx][1][1] = (dp[idx][1][1] - dp_sum[prod][0][0]) % MOD;
				}
				else
				{
					dp[idx][1][0] = (dp[idx][1][0] + dp_sum[prod][0][1]) % MOD;
					dp[idx][1][1] = (dp[idx][1][1] + dp_sum[prod][0][0]) % MOD;
				}
			}
			for (auto divisor : divisors[idx])
			{
				dp_sum[divisor][1][0] = (dp_sum[divisor][1][0] + dp[idx][1][0]) % MOD;
				dp_sum[divisor][1][1] = (dp_sum[divisor][1][1] + dp[idx][1][1]) % MOD;
			}
		}
		for (lll idx = 1; idx <= n; idx++)
		{
			dp[idx][0][0] = dp[idx][1][0];
			dp[idx][0][1] = dp[idx][1][1];
			dp_sum[idx][0][0] = dp_sum[idx][1][0];
			dp_sum[idx][0][1] = dp_sum[idx][1][1];
			dp[idx][1][0] = 0;
			dp[idx][1][1] = 0;
			dp_sum[idx][1][0] = 0;
			dp_sum[idx][1][1] = 0;
		}
	}
	cout << (dp[y][0][1] % MOD + MOD) % MOD << "\n";
}