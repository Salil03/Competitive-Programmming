#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    int n = 0;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i <= j)
                {
                    if (((arr[i] ^ arr[j]) > 3) && ((arr[i] ^ arr[j]) % 2 == 0))
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}