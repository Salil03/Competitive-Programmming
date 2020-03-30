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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	lll arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	lll prefix[n];
	prefix[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		prefix[i] = prefix[i - 1] + arr[i];
	}
	lll sum = 0;
	if (prefix[n - 1] % 3 != 0)
	{
		cout << 0;
		return 0;
	}
	else
	{
		sum = prefix[n - 1] / 3;
	}
	lll cnt = 0;
	lll index[n] = {0};
	if (prefix[0] == sum)
	{
		index[0] = 1;
	}
	for (int i = 1; i < n - 2; i++)
	{
		if (prefix[i] == sum)
		{
			index[i] = index[i - 1] + 1;
		}
		else
		{
			index[i] = index[i - 1];
		}
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (prefix[i] == 2 * sum)
		{
			cnt += index[i - 1];
		}
	}
	cout << cnt;
}