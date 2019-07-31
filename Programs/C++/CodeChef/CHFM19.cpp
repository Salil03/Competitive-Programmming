#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/JULY19B/problems/CHFM

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
		long long arr[n];
		long long sum = 0;
		for(int i =0; i<n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		if(sum % n == 0)
		{
			sum /=n;
		}
		else
		{
			cout << "Impossible\n";
			continue;
		}
		bool flag = false;
		for(int i = 0; i<n; i++)
		{
			if(arr[i] == sum)
			{
				cout << i+1 << "\n";
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			cout << "Impossible\n";
		}
	}
}