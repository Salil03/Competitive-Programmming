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
const int MOD = 998244353;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
long long binpow(long long a, long long b)
{
	if (b == 0)
		return 1;
	long long res = binpow(a, b / 2);
	if (b % 2)
		return ((res) % MOD * (res) % MOD * (a) % MOD) % MOD;
	else
		return ((res) % MOD * (res) % MOD) % MOD;
}

lll recur(lll num, lll cnt[], lll n)
{
	if (num == 1)
	{
		return (binpow(2, cnt[num] + 1) - 1);
	}
	else
	{
		return recur(num - 1, cnt, n) * (binpow(2, cnt[num]) - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll t;
	cin >> t;
	while (t--)
	{
		lll n;
		cin >> n;
		lll arr[n];
		for (lll i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		lll freq[n + 4] = {0};
		for (int i = 0; i < n; i++)
		{
			if (arr[i] <= n + 2)
			{
				freq[arr[i]]++;
			}
			else
			{
				freq[n + 3]++;
			}
		}
		lll suffix[n + 4] = {0};
		suffix[n + 3] = freq[n + 3];
		for (int i = n + 2; i >= 0; i--)
		{
			suffix[i] = suffix[i + 1] + freq[i];
		}
		lll ans = 0;
		for (int m = 1; m <= n + 1; m++)
		{
			lll cnt = 1;
			bool flag = false;
			for (int i = 1; i < m; i++)
			{
				cnt *= (binpow(2, freq[i]) - 1) % MOD;
			}
			ans += ((m % MOD) * (binpow(2, suffix[m + 1]) % MOD) * (cnt % MOD)) % MOD;
		}
		cout << (ans+MOD) % MOD << "\n";
	}
}