#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=0;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int l[n];
        int r[n];
        for(int i =0; i < n; i++)
        {
            cin >> l[i];
            cin >> r[i];
        }
        sort(l, l+n);
        sort(r, r+n);
        int temp=0;
        for(int i =0; i< m; i++)
        {
            cin >> temp;
            if(temp > r[n-1])
            {
                cout << -1 << "\n";
            }
            else if(*lower_bound(l,l+n,temp) == temp)
            {
                cout << 0 << "\n";
            }
        }
    }
}
