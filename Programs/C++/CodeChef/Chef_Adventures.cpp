#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        if ((n - 1) % x == 0 && (m - 1) % y == 0)
        {
            if ((n - 1) < 0 || (m - 1) < 0)
            {
                cout << "Pofik\n";
            }
            else
            {
                cout << "Chefirnemo\n";
            }
        }
        else if ((n - 2) % x == 0 && (m - 2) % y == 0)
        {
            if ((n - 2) < 0 || (m - 2) < 0)
            {
                cout << "Pofik\n";
            }
            else
            {
                cout << "Chefirnemo\n";
            }
        }
        else if ((n - 2) == 0 && (m - 2) == 0)
        {
            cout << "Chefirnemo\n";
        }
        else
        {
            cout << "Pofik\n";
        }
    }
}