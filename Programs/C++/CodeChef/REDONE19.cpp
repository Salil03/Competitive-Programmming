#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
	$alil03

	URL: https://www.codechef.com/MAY19B/problems/REDONE

	Solution Begins here
	*/

long long int facto[1000004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int fact = 1;
	for (int i = 1; i <= 1000003; i++)
	{
		fact = (fact * i) % MOD;
		facto[i] = fact;
	}
	int t;
	cin >> t;
	while (t--)
	{
		long long int n;
		cin >> n;
		n++;
		cout << facto[n] - 1 << "\n";
	}
}