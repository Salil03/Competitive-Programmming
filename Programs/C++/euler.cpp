#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

/*
$alil03
Solution Begins here
*/


int main()
{
	cpp_int num = 2;
	for(int i = 1; i<1000; i++)
	{
		num *= 2;
	}
	int sum = 0;
	for(char i: to_string(num))
	{
		sum += i-'0';
	}
}