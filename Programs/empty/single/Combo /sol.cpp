//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
#include<combo.h>
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
 
string guess_sequence(int n)
{
	char first = 'A';
	if(press("A") == 1)
	{
		first = 'A';
	}
	else if(press("B") == 1)
	{
		first = 'B';
	}
	else if(press("X") == 1)
	{
		first = 'X';
	}
    else
	{
		first = 'Y';
	}
	int temp = 2;
	n--;
	string s = "ABXY";
	string ans = "";
	ans += first;
	while(n--)
	{
		for(int i = 0; i<4; i++)
		{
			if(s[i] == first)
			{
				continue;
			}
			if(i == 2 && s[3] == first)
			{
				ans += s[2];
				temp++;
				break;
			}
			if(i == 3)
			{
				ans += s[3];
				temp++;
				break;
			}
			if(press(ans + s[i]) == temp)
			{
				ans += s[i];
				temp++;
				break;
			}
		}
	}
	return ans;
}