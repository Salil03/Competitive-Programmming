#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0, n = 0, ans = 0;
    cin >> t;
    int arr[] = {1, 2, 5, 10, 50, 100};
    while (t--)
    {
        cin >> n;
        ans = 0;
        while (n > 0)
        {
            n -= *(upper_bound(arr, arr + 6, n) - 1);
            ans++;
        }
        cout << ans << "\n";
    }
}