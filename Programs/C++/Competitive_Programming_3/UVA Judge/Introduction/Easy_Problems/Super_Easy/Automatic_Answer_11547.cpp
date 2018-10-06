#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t =0;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << (abs((((((n*567)/9)+7492)*235)/47)-498) / 10) % 10 << "\n";
	}
	return 0;
}