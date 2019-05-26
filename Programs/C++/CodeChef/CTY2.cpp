#include<bits/stdc++.h>
using namespace std;
int count( int coins[], int m, int n )
{
    int table[n+1] = {0};


    table[0] = 1;

    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<m; i++)
        for(int j=coins[i]; j<=n; j++)
            table[j] += table[j-coins[i]];

    return table[n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int coins[m];
	for(int i = 0; i<m; i++)
	{
		cin >> coins[i];
	}
	cout << count(coins, m, n);
}