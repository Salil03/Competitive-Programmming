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
int n, m, k;
int dp(int day, int subject, int a[], int b[], int work)
{
	if (day == n + 1)
	{
		return 0;
	}
	if (subject == m)
	{
		return INT_MIN;
	}
	if (day == 1)
	{
		int ans = max(0, dp(day, subject + 1, a, b, 0));
		for (int i = a[subject]; i <= b[subject]; i++)
		{
			ans = max(ans, i + dp(day + 1, subject + 1, a, b, i));
		}
		return ans;
	}
	int ans = 0;
	if (work + k >= a[subject] && work + k <= b[subject])
	{
		ans = max(ans, work + k + dp(day + 1, subject + 1, a, b, work + k));
	}
	if (work * k >= a[subject] && work * k <= b[subject])
	{
		ans = max(ans, work * k + dp(day + 1, subject + 1, a, b, work * k));
	}
	ans = max(ans, dp(day, subject + 1, a, b, work));
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int a[m], b[m];
	pair<int, int> c[m];
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		cin >> b[i];
		cin >> c[i].first;
		c[i].second = i;
	}
	sort(c, c + m);
	int new_a[m], new_b[m];
	for (int i = 0; i < m; i++)
	{
		new_a[i] = a[c[i].second];
		new_b[i] = b[c[i].second];
	}
	cout << dp(1, 0, new_a, new_b, 0);
}