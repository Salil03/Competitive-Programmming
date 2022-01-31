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
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int n = n1 + n2 + n3;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	vector<int> final;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			final.push_back(arr[i]);
			i++;
		}
	}
	cout << final.size() << "\n";
	for (int i : final)
	{
		cout << i << "\n";
	}
}