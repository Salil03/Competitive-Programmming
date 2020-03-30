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
const int MAX = 1e5; // limit for array size
int n;				 // array size
int tree[2 * MAX];

void build()
{
	for (int i = n - 1; i > 0; i--)
	{
		tree[i] = max(tree[i * 2], tree[(i * 2) | 1]);
	}
}
int query(int l, int r)
{ // sum on interval [l, r)
	int res = 0;
	l += n;
	r += n;
	for (; l < r; l /= 2, r /= 2)
	{
		if (l & 1)
		{
			res = max(res, tree[l]);
			l++;
		}
		if (r & 1)
		{
			r--;
			res = max(res, tree[r]);
		}
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tree[n + i];
	}
	build();
	cout << query(0, n);
}