#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	cin >> n;
	char s[n];
	cin >> s[0];
	for(int i = 1;i<n; i++)
	{
		cin >> s[i];
		if(s[i] == s[i-1])
		{
			ans++;
		}
	}
	cout << ans;
}