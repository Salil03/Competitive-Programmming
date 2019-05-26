#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,w;
    cin >> n >> w;
    long long weight[n];
    long long value[n];
    for(long long i = 0; i<n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    long long knap[n+1][w+1];
    for(long long i = 0; i<=n; i++)
    {
        for(long long j = 0; j<=w; j++)
        {
            if(i == 0 || j == 0)
            {
                knap[i][j] = 0;
            }
            else if(weight[i-1] <= j)
            {
                knap[i][j] = max(value[i-1]+ knap[i-1][j-weight[i-1]], knap[i-1][j]);
            }
            else
            {
                knap[i][j] = knap[i-1][j];
            }
        }
    }
    cout << knap[n][w];
}
