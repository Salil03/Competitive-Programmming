#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0, n = 0, k = 0, temp = 0, count = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        count = 0;
        for (int x = 0; x < n; x++)
        {
            cin >> temp;
            if ((k - temp) > count)
            {
                count = k - temp;
            }
        }
        cout << count << "\n";
    }
}