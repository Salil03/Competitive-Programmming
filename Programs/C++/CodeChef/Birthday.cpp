#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    double arr[n] = {0};
    double x;
    int y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if ((y <= m) && (x * ((m - (m % y)) / y) >= k))
        {
            arr[i] = x * ((m - (m % y)) / y);
        }
    }
    if (*max_element(arr, arr + n) == 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES " << *max_element(arr, arr + n);
    }
}