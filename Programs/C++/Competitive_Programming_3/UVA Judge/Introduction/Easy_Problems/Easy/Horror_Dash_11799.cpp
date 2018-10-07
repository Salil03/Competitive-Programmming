#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i =0; i< t; i++)
    {
        int n;
        cin >> n;
        int ans = 0;
        int temp;
        while(n--)
        {
            cin >> temp;
            if(temp > ans)
            {
                ans = temp;
            }
        }
        cout << "Case " << i+1 << ": " << ans << "\n";
    }
}
