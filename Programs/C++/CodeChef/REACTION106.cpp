#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/COOK106B/problems/REACTION

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
		int r,c;
		cin >> r >> c;
		watch(r);
		watch(c);
		int arr[r][c] = {{0}};
		for(int i = 0; i<r; i++)
		{
			for(int j = 0; j<c; j++)
			{
				cin >> arr[i][j];
			}
		}
		if(arr[0][0] >= 2 || arr[r-1][c-1] >= 2 || arr[r-1][0] >= 2 || arr[0][c-1] >= 2)
		{
			cout << "Unstable\n";
			continue;
		}
		bool flag = true;
		for(int i = 1; i<r-1; i++)
		{
			if(arr[i][0] > 2 || arr[i][c-1] > 2)
			{
				flag = false;
				break;
			}
		}
		for(int i = 1; i<c-1; i++)
		{
			if(arr[0][i] > 2 || arr[r-1][i] > 2)
			{
				flag = false;
				break;
			}
		}
		for(int i = 1; i<r-1; i++)
		{
			for(int j = 1; j<c-1; j++)
			{
				if(arr[i][j] > 3)
				{
					flag = false;
					break;
				}
			}
			if(!flag)
			{
				break;
			}
		}
		if(!flag)
		{
			cout << "Unstable\n";
		}
		else
		{
			cout << "Stable\n";
		}
		
	}
}