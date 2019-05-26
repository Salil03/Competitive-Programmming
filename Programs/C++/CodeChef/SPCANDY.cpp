#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long n,k;
		cin >> n >> k;
		if(n == 0)
		{
			cout << 0 << " " << 0<< "\n";
			continue;
		}
		else if(k == 0)
		{
			cout << 0 << " " << n << "\n";
			continue;
		}
		cout << n/k << " " << n%k << "\n";
	}	
}