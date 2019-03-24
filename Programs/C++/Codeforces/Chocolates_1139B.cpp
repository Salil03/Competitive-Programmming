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
	int n;
	cin >> n;
	int arr[n];
	for(int i =0; i<n; i++)
	{
		cin >> arr[i];
	}
	int maximum = -INF, sum = 0;
	for(int i = n-1; i>=0; i--)
	{
		sum = arr[i];
		for(int j = i-1; j>=0; j--)
		{
			if(arr[j] < arr[j+1])
			{
				sum += arr[j];
			}
			else
			{
				sum += max(arr[j+1]-1,0);
				arr[j] = max(arr[j+1]-1,0);;
			}
		}
		maximum = max(maximum, sum);
	}
	cout << maximum;
}