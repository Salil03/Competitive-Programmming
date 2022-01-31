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
	int n;
	cin >> n;
	vector<int> arr[n];
	bool ascent[n] = {0};
	lll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int l;
		cin >> l;
		if (l > 1)
		{
			ans++;
		}
		arr[i].resize(l);
		for (int j = 0; j < l; j++)
		{
			cin >> arr[i][j];
		}
		for (int j = 1; j < l; j++)
		{
			if (arr[j] > arr[j - 1])
			{
				ascent[i] = 1;
				ans += n;
				break;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (!ascent[i])
		{
			cnt++;
		}
	}
	ans += cnt * (cnt - 1) / 2;
	cout << ans;
}