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
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

bool dp(int rem, int idx, vector<int> factors, int n, int k)
{
	if (k == 1)
	{
		return (rem == factors[idx]);
	}
	if (idx == n)
	{
		return false;
	}
	if (rem < factors[idx])
	{
		if (dp(rem, idx + 1, factors, n, k))
		{
			cout << factors[idx] << " ";
			return true;
		}
		return false;
	}
	if (dp(rem, idx + 1, factors, n, k))
	{
		cout << factors[idx] << " ";
		return true;
	}
	if (dp(rem - factors[idx], idx + 1, factors, n, k - 1))
	{
		cout << factors[idx] << " ";
		return true;
	}
	return false;
}

int main()
{
	int s, p, k;
	cin >> s >> p >> k;
	vector<int> factors;
	for (int i = 1; i <= p; i++)
	{
		if (p % i == 0)
		{
			factors.push_back(i);
		}
	}
	int n = factors.size();
	dp(s, 0, factors, n, k);
}