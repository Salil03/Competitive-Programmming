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
	int v;
	cin >> v;
	pair<int, int> arr[9];
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr, arr + 9);
	int idx = 0, minimum = arr[0].first;
	for (int i = 0; i < 9; i++)
	{
		if (arr[i].first <= arr[idx].first && arr[i].second > arr[idx].second)
		{
			minimum = arr[i].first;
			idx = i;
		}
	}
	if (v < arr[idx].first)
	{
		cout << -1;
		return 0;
	}
	while (v - arr[idx].first >= arr[idx].first)
	{
		v -= arr[idx].first;
		cout << arr[idx].second;
	}
	int maximum = arr[idx].second;
	for (int i = 0; i < 9; i++)
	{
		if (v >= arr[i].first)
		{
			maximum = max(maximum, arr[i].second);
		}
	}
	cout << maximum;
}