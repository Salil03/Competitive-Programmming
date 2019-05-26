#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

/*
$alil03
Solution Begins here
*/
int fib(int n)
{
    int a = 1, b = 1, c, i;
    if( n == 1 || n==2)
      return n;
    for (i = 2; i <= n; i++)
    {
      c = (a + b)%15746;
      a = b%15746;
      b = c%15746;
    }
    return b%15746;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cout << fib(n);
}