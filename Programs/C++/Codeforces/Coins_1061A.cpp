#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,s;
	cin >> n >> s;
	long long ans = 0;
	while(s>0)
	{
		if(n<=s)
		{
			ans += s/n;
			s = s%n;
		}
		else
		{
			n--;
		}
	}
	cout << ans;
}