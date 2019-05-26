#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 0, n = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n % 2 == 1)
        {
            cout << accumulate(arr, arr + ((n - 1) / 2), 0) << " " << accumulate(arr + ((n - 1) / 2) + 1, arr + n, 0) << "\n";
            if ((accumulate(arr, arr + ((n - 1) / 2), 0)) / 2 <= accumulate(arr + ((n - 1) / 2) + 1, arr + n, 0))
            {
                cout << "Motu\n";
            }
            else
            {
                cout << "Patlu\n";
            }
        }
        else
        {
            cout << accumulate(arr, arr + ((n - 1) / 2), 0) << " " << accumulate(arr + ((n - 1) / 2) + 1, arr + n, 0) << "\n";
            if ((accumulate(arr, arr + ((n - 1) / 2), 0)) / 2 <= accumulate(arr + ((n - 1) / 2) + 1, arr + n, 0))
            {
                cout << "Motu\n";
            }
            else
            {
                cout << "Patlu\n";
            }
        }
    }
}