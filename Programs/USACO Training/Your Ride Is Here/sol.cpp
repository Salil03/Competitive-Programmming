/*
ID: salilgo1
PROG: ride
LANG: C++14                
*/

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
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	string a, b;
	cin >> a >> b;
	int x = 1, y = 1;
	for (char i : a)
	{
		x *= i - 64;
		x %= 47;
	}
	for (char i : b)
	{
		y *= i - 64;
		y %= 47;
	}
	if (x == y)
	{
		cout << "GO\n";
	}
	else
	{
		cout << "STAY\n";
	}
	return 0;
}