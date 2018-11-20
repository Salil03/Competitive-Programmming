#include<bits/stdc++.h>
using namespace std;
bool arr[1000000000] = {0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long m, n;
        cin >> m >> n;
        for(long long i = 2; i<=n; i++)
        {
            if(arr[i]) continue;
            else
            {
                if(i >= m) cout << i << "\n";
                for(long long j = 2*i; j<=n; j+=i)
                {
                    arr[j] = i;
                } 
            }  
        }
        cout << "\n";
    }
}