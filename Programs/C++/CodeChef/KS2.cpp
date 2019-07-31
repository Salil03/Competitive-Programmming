#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/JUNE19B/problems/KS2

Solution Begins here
*/
unsigned long long int digsum(unsigned long long int x) 
{ 
	unsigned long long int accu = 0; 
	while (x > 0)
	{ 
		accu += x % 10; 
		x /= 10; 
	} 
	return accu; 
} 

unsigned long long int nth(unsigned long long int l) 
{ 
	unsigned long long int cumulative = digsum(l); 
	unsigned long long int cumu2 = 10 - (cumulative % 10);
	cout << l;
	return cumu2;
} 

  
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		unsigned long long int n;
		cin >> n;
		cout << nth(n) << "\n";	
	}
}