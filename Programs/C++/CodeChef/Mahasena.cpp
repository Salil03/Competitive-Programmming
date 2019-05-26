#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0, s = 0, ans = 0;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s & 1)
        {
            ans--;
        }
        else
        {
            ans++;
        }
    }
    if (ans > 0)
    {
        cout << "READY FOR BATTLE";
    }
    else
    {
        cout << "NOT READY";
    }
}