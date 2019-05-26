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
		long long a,b,k, ans =0;
		cin >> a >> b >> k;
		if(k&1)
		{
			ans+=a;
			k /= 2;
			while(k--)
			{
				ans -=b;
				ans += a;
			}
		}
		else
		{
			k = k/2;
			while(k--)
			{
				ans += a;
				ans -= b;
			}
		}
		cout << ans << "\n";
	}
}