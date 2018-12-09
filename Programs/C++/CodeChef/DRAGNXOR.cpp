#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, a, b, a0, b0, a1, b1;
	cin >> t;
	while(t--)
	{
		cin >> n >> a >>b;
		a1 = __builtin_popcount(a);
		a0 = n - a1;
		b1 = __builtin_popcount(b);
		b0 = n - b1;
		int ones = min(a1,b0) + min(b1,a0);
		cout << (((1<<ones)-1) << (n-ones)) << "\n";
	}

	return 0;
}
