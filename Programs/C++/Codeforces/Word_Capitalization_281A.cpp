#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >>s;
	transform(s.begin(), s.begin()+1, s.begin(), ::toupper);
	cout << s;
}