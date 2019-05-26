#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
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
	int n;
	cin >> n;
	bool arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	int maximum = INT_MIN;
	for(int i = 0; i<n; i++)
	{
		for(int j = i; j<n; j++)
		{
			int sum = 0;
			for(int k = 0; k<i; k++)
			{
				if(arr[k] == 1)
				{
					sum++;
				}
			}
			for(int k = i; k<=j; k++)
			{
				if(arr[k] == 0)
				{
					sum++;
				}
			}
			for(int k = j+1; k<n; k++)
			{
				if(arr[k] == 1)
				{
					sum++;
				}
			}
			maximum = max(sum, maximum);
		}
	}
	cout << maximum;
}