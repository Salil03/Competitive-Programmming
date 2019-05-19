#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/COOK105B/problems/CFMM

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[6] = {0}; //codehf
		while (n--)
		{
			string s;
			cin >> s;
			for (char i : s)
			{
				if (i == 'c')
				{
					arr[0]++;
				}
				else if (i == 'o')
				{
					arr[1]++;
				}
				else if (i == 'd')
				{
					arr[2]++;
				}
				else if (i == 'e')
				{
					arr[3]++;
				}
				else if (i == 'h')
				{
					arr[4]++;
				}
				else if (i == 'f')
				{
					arr[5]++;
				}
			}
		}
		arr[0] /= 2;
		arr[3] /= 2;
		cout << *min_element(arr, arr + 6) << "\n";
	}
}