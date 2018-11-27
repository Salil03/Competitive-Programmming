#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int x;
	int prefix[n+1];
	prefix[0] = 0;
	for(int i = 1; i<=n; i++)
	{
		cin >> x;
		prefix[i] = x+prefix[i-1];
	}
	int q;
	cin >> q;
	while(q--)
	{
		cin >> x >> n;
		cout << prefix[n+1] - prefix[x] << "\n";
	}
}