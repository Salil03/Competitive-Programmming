#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int q = 0;
    cin >> q;
    int l, r, x;
    while (q--)
    {
        cin >> l >> r >> x;
        bool found = false;
        for (int i = l; i <= r; i++)
        {
            if (arr[i] == x)
            {
                cout << "yes\n";
                found = true;
                break;
            }
        }
        if (found == false)
        {
            cout << "no\n";
        }
    }
}