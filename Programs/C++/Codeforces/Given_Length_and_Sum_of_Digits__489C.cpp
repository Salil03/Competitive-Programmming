#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

/*
$alil03
Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,s;
	cin >> m >> s;
	if(s==0)
	{
		cout << (m==1 ? "0 0" : "-1 -1");
		return 0;
	}
	string a = "",b = "";
	for(int i = 0; i<m; i++)
	{
		a += to_string(min(s, 9));
		s -= min(s, 9);
	}

	if(s > 0)
	{
		cout << "-1 -1";
		return 0;
	}
	b = a;
	reverse(b.begin(), b.end());
	int zero = 0;
	for(zero = 0; b[zero] == '0'; zero++);

	b[0]++;
    b[zero]--;
    cout << b << " " << a;
}