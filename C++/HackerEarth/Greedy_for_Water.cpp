#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, x, k = 1;
    cin >> t;
    do
    {
        cin >> n >> x;
        int a[n], num = 0, cp = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            cp += a[i];
            if (cp > x)
                break;
            num++;
        }
        cout << num << '\n';
        k++;
    } while (k <= t);
    return 0;
}