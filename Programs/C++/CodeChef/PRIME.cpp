#include<bits/stdc++.h>
using namespace std;
int arr[100000] = {2, 0};
void calc_primes(int x)
{
	for(int i = 3; i<=x; i++)
	{
		bool prime = true;
		int temp = 0;
		for(int j:arr)
		{
			if(i%j == 0 || j == 0)
			{
				prime = false;
				break;
			}
			temp = j;
		}
		if(prime)
		{
			arr[temp] = i;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int m,n;
		cin >> m >>n;
		calc_primes(m);
		cout << arr[0]  << arr[1]<< arr[2] << arr[3] << arr[4];
	}
}