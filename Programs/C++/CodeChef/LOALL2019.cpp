#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/DARG2019/problems/LOALL

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[10] = {0};
	while (n--)
	{
		string s;
		cin >> s;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			arr[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i;
		}
	}
	cout << "\n";
}