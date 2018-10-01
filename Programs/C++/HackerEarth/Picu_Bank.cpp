#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 0, d = 0, a = 0, m = 0, b = 0, x = 0;
    cin >> t;
    while (t--)
    {
        cin >> d >> a >> m >> b >> x;
        int ans = 0;
        while (d < x)
        {
            if (ans % (m + 1) == 0)
            {
                d += b;
                ans++;
            }
            else
            {
                d += a;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
