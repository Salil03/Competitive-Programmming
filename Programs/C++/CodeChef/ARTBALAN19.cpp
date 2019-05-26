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
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.length();
		int arr[26], cnt = 0;
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i<n; i++)
		{
			if(arr[s[i] - 'A'] == 0)
			{
				cnt++;
			}
			arr[s[i]- 'A']++;
		}
		int mean = n/cnt;
		sort(arr, arr+26, greater<int>());
	}
}