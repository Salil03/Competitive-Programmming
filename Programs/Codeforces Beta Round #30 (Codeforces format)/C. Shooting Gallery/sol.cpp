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

bool sortbyth(const tuple<lll, lll, lll, double> &a,
			  const tuple<lll, lll, lll, double> &b)
{
	return (get<2>(a) < get<2>(b));
}

double dist[1010][1010];
tuple<lll, lll, lll, double> points[1010];
int n;

map<lll, double> mp;

double dp(lll idx)
{
	if (idx == n)
	{
		return 0;
	}
	if (mp.find(idx) != mp.end())
	{
		return mp[idx];
	}
	double maximum = get<3>(points[idx]);
	for (int i = idx + 1; i < n; i++)
	{
		if (get<2>(points[i]) - get<2>(points[idx]) >= dist[idx][i])
		{
			maximum = max(maximum, get<3>(points[idx]) + dp(i));
		}
	}
	return mp[idx] = maximum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		lll x, y, z;
		double d;
		cin >> x >> y >> z >> d;
		points[i] = make_tuple(x, y, z, d);
	}
	sort(points, points + n, sortbyth);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = sqrt((get<0>(points[i]) - get<0>(points[j])) * (get<0>(points[i]) - get<0>(points[j])) + (get<1>(points[i]) - get<1>(points[j])) * (get<1>(points[i]) - get<1>(points[j])));
		}
	}
	double maximum = 0;
	for (int i = 0; i < n; i++)
	{
		maximum = max(maximum, dp(i));
		mp.clear();
	}
	cout << fixed << setprecision(10) << maximum;
}