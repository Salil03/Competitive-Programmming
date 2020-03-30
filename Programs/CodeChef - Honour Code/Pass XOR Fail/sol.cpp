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
void increment_numerical_string(std::string &s)
{
	std::string::reverse_iterator iter = s.rbegin(), end = s.rend();
	int carry = 1;
	while (carry && iter != end)
	{
		int value = (*iter - '0') + carry;
		carry = (value / 10);
		*iter = '0' + (value % 10);
		++iter;
	}
	if (carry)
		s.insert(0, "1");
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = 0;
	if (s.length() > 1)
	{
		n = s[s.length() - 1] + s[s.length() - 2] * 10;
	}
	else
	{
		n = s[s.length() - 1];
	}
	if (n % 4 == 0)
	{
		cout << s;
	}
	else if (n % 4 == 1)
	{
		cout << 1;
	}
	else if (n % 4 == 2)
	{
		increment_numerical_string(s);
		cout << s;
	}
	else
	{
		cout << 0;
	}
}