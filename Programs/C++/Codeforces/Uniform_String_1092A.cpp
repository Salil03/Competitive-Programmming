#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s = "abcdefghijklmnopqrstuvwxyz";
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int i = 0;
		while(n--)
		{
			cout << s[i];
			if(i == k-1)
			{
				i = 0;
			}
			else
			{
				i++;
			}
		}
		cout << "\n";
	}
}