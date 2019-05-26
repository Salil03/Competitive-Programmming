#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int maximum = -1, temp, cnt = 0;
	while(n--)
	{
		cin >> temp;
		cnt -= temp;
		cin >> temp;
		cnt += temp;
		maximum = max(cnt, maximum);
	}
	cout << maximum;
}