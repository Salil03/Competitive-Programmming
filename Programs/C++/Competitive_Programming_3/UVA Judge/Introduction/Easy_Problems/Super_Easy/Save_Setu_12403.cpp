#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int ans =0;
    while(t--)
    {
        string operation = "";
        cin >> operation;
        if(operation == "donate")
        {
            int k;
            cin >> k;
            ans += k;
        }
        else
        {
            cout << ans << "\n";
        }
    }
}
