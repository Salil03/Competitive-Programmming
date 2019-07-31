#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/LTIME73B/problems/SILLYPRS

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
		int n;
		cin >> n;
		long long int a[n];
		long long int b[n];
		unsigned long long int sum = 0;
		int even1= 0, odd1 = 0, even2= 0, odd2 = 0;
		for(int i = 0; i<n; i++)
		{
			cin >> a[i];
			if(a[i] & 1)
			{
				odd1++;
			}
			else
			{
				even1++;
			}
			sum += a[i];
		}
		for(int i = 0; i<n; i++)
		{
			cin >> b[i];
			if(b[i] & 1)
			{
				odd2++;
			}
			else
			{
				even2++;
			}
			sum += b[i];
		}
		sum -= (max(even1, even2) - min(even1,even2));
		cout << sum/2 << "\n";
	}
}