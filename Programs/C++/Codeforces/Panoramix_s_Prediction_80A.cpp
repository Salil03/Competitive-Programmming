#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	int n,m;
	cin >> n >> m;
	if(m == *upper_bound(primes, primes+16, n))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}