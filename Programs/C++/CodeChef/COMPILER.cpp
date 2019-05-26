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
		string s;
		cin >> s;
		int sum = 0, n = s.length(), maximum = 0;
		bool wrong = true;
		for(int i = 0; i<n; i++)
		{
			if(s[i] == '<')
			{
				sum++;
			}
			else
			{
				sum--;
			}
			if(sum == 0 && wrong)
			{
				maximum = i+1;
			}
			if(sum < 0)
			{
				wrong = false;
			}
		}
		cout << maximum << "\n";
	}
}