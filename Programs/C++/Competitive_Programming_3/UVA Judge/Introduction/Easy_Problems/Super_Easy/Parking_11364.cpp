#include<bits/stdc++.h>
using namespace std;
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
        int shops[n];
        for(int i =0; i< n; i++)
        {
            cin >> shops[i];
        }
        sort(shops, shops+n);
        cout << (shops[n-1] - shops[0])*2 << "\n";
    }
}
