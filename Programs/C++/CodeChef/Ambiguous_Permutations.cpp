#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a = 0;
    while (true)
    {
        cin >> a;
        if (a == 0)
        {
            break;
        }
        int arr[a];
        string ans = "ambiguous";
        for (int i = 0; i < a; i++)
        {
            cin >> arr[i];
        }
        for (int j = 1; j <= a; j++)
        {
            if (arr[arr[j - 1] - 1] != j)
            {
                ans = "not ambiguous";
            }
        }
        cout << ans << "\n";
    }
}