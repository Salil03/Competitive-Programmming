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

int fill(int a, int b, int arr[], map<pair<int, int>, int> sparse)
{
	if (sparse.find({a, b}) != sparse.end())
	{
		return sparse[{a, b}];
	}
	int cnt = (b - a + 1) / 2;
	sparse[{a, b}] = min(sparse[{a, a + cnt - 1}], sparse[{a + cnt, b}]);
	return sparse[{a, b}];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	map<pair<int, int>, int> sparse;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sparse[{i, i}] = arr[i];
	}
	fill(0, n - 1, arr, sparse);
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		int k = (int)log2(y - x + 1);
		cout << min(sparse[{x, x + k - 1}], sparse[{y - k + 1, y}]) << "\n";
	}
}