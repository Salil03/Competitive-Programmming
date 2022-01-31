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
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n;
	cin >> n;
	lll arr[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	lll suffix[n];
	suffix[n - 1] = arr[n - 1];
	for (lll i = n - 2; i >= 0; i--)
	{
		suffix[i] = suffix[i + 1] + arr[i];
	}
	lll minima[n];
	minima[n - 1] = arr[n - 1];
	for (lll i = n - 2; i >= 0; i--)
	{
		minima[i] = min(minima[i + 1], arr[i]);
	}
	lll k[n - 1];
	for (lll i = 1; i <= n - 2; i++)
	{
		lll score = suffix[i];
		score -= minima[i];
		score /= n - i - 1;
		k[i] = score;
	}
	lll maxima = *max_element(k + 1, k + n - 2);
	for (lll i = 1; i <= n - 2; i++)
	{
		if (k[i] == maxima)
		{
			cout << i << "\n";
		}
	}
}