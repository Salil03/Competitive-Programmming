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
		int n;
		cin >> n;
		n--;
		int x;
		cin >> x;
		int ans = x;
		while(n--)
		{
			cin >> x;
			ans = __gcd(x,ans);
		}
		cout << ans << "\n";
	}
}