#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while(n--)
    {
        long long w,h;
        cin >> w >> h;
        if((double)w/h*10 >=16 && (double)w/h*10 <= 17)
        {
            ans++;
        }
    }
    cout << ans;
}