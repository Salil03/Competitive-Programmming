#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/DARG2019/problems/SUMMOD

Solution Begins here
*/

long long fact[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fact[0] = 1;
	for (long long i = 1; i < 100005; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += fact[i];
			sum %= MOD;
		}
		cout << sum << "\n";
	}
}