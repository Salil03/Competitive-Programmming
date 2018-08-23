#include <bits/stdc++.h>
using namespace std;
int search(int m, int a[], int n)
{
    for (int i = (n - 1); i > -1; i--)
    {
        if (a[i] == m)
        {
            return i + 1;
        }
    }
    return -1;
}
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << search(m, a, n);
}
