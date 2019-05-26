#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/DARG2019/problems/GMPOW

Solution Begins here
*/

cpp_int binpow(cpp_int a, cpp_int b)
{
	cpp_int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

bool isPrime(cpp_int n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (cpp_int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cpp_int a;
		cin >> a;
		cpp_int n;
		cin >> n;
		cpp_int ans = binpow(a, n);
		cpp_int sum = 0;
		while (ans > 0)
		{
			sum += ans % 10;
			ans /= 10;
		}
		cout << isPrime(sum) << "\n";
	}
}