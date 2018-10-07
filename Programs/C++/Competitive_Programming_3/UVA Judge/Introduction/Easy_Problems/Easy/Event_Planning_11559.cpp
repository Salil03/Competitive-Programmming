#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,b,h,w;
    while(cin >> n >> b >> h >> w)
    {
        int p;
        int ans = INT_MAX;
        bool allow = false;
        while(h--)
        {
            cin >> p;
            int a;
            for(int i =0; i < w; i++)
            {
                cin >> a;
                if(a >= n)
                {
                    allow = true;
                }
            }
            if(allow == true)
            {
                if(p*n < ans)
                {
                    ans = p*n;
                }
            }
            allow = false;
        }
        if(ans <= b)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << "stay home\n";
        }
    }
}
