#include<bits/stdc++.h>
using namespace std;
void binary(int &n)
{
    int binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    n = binaryNumber;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long l,r,v;
		long long ans = 1;
		cin >> l >> r >> v;
		int pop = __builtin_popcountll(v);
	}
}