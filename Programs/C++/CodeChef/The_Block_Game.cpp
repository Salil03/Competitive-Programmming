#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    string n = "";
    string n_reverse = "";
    cin >> t;
    while (t--)
    {
        cin >> n;
        n_reverse = n;
        reverse(n.begin(), n.end());
        if (n == n_reverse)
        {
            cout << "wins\n";
        }
        else
        {
            cout << "losses\n";
        }
    }
}