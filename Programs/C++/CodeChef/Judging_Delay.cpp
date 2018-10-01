#include<iostream>
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
        int n;
        cin >> n;
        int ans =0;
        int x,y;
        while(n--)
        {
            cin >> x >> y;
            if(y-x > 5)
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
