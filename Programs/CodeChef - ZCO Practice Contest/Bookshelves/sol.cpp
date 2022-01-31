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

lll solve(lll a[], lll b[], lll n, lll k)
{
	lll temp1[n];
	lll temp2[n];
	for (int i = 0; i < n; i++)
	{
		temp1[i] = a[i];
		temp2[i] = b[i];
	}
	lll cnt = k;
	lll big = 0;
	lll small = n - 1;
	while (cnt > 0)
	{
		if (temp1[small] <= temp2[big] || small < 0 || big >= n)
		{
			break;
		}
		if (temp1[small] > temp2[big])
		{
			swap(temp1[small], temp2[big]);
			cnt--;
			small--;
			big++;
		}
	}
	sort(temp2, temp2 + n);
	sort(temp1, temp1 + n);
	return temp1[n - 1] + temp2[n - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll n, k;
	cin >> n >> k;
	lll a[n];
	lll b[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (lll i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	cout << min(solve(a, b, n, k), solve(b, a, n, k));
}