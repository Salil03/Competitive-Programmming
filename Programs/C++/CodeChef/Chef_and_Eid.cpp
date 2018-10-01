#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0, n = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        int s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for (int j = 0; j < n; j++)
        {
            s[j] = arr[j + 1] - arr[j];
        }
        sort(s, s + n);
        cout << s[0] << "\n";
    }
}