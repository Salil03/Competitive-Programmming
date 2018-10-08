#include <bits/stdc++.h>
using namespace std;
bool search(int arr[], int n, int x)
{
    // 1st comparison
    if (arr[n - 1] == x)
        return true;

    int backup = arr[n - 1];
    arr[n - 1] = x;

    // no termination condition and thus
    // no comparison
    for (int i = 0;; i++)
    {
        // this would be executed at-most n times
        // and therefore at-most n comparisons
        if (arr[i] == x)
        {
            // replace arr[n-1] with its actual element
            // as in original 'arr[]'
            arr[n - 1] = backup;

            // if 'x' is found before the '(n-1)th'
            // index, then it is present in the array
            // final comparison
            if (i < n - 1)
                return true;

            // else not present in the array
            return false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
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
            if (r >= n || l < 0)
            {
                cout << "no\n";
                continue;
            }
            if (search(arr, r + 1 - l, x))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}