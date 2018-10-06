#include<iostream>
using namespace std;
int main()
{
    int ans;
    int a,b,c,d;
    while(cin >> a >> b >> c >> d)
    {
        if(a == 0 && b == 0 && c == 0 && d == 0)
        {
            cout << 1890;
            break;
        }
        ans = 1080;
        if(a >= b)
        {
            ans += (a-b)*9;
        }
        else
        {
            ans += (40 - b + a)*9;
        }
        if(b <= c)
        {
            ans += (c-b)*9;
        }
        else
        {
            ans += (40 - b + c)*9;
        }
        if(c >= d)
        {
            ans += (c-d)*9;
        }
        else
        {
            ans += (40 - d + c)*9;
        }
        cout << ans << "\n";
    }
}
