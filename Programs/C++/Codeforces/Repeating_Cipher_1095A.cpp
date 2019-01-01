#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int i = 0;
	for(int j = 0; j<n; j+= i)
	{
		cout << s[j];
		i++;
	}
}