#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m = 0;
    cin >> m;
    if ((m == 2) || (m == 3))
    {
        cout << "NO SOLUTION";
    }
    else if (m == 4)
    {
        cout << 2 << " " << 4 << " " << 1 << " " << 3;
    }
    else if (m > 4)
    {
        int i = 1;
        while (i <= m)
        {
            cout << i << " ";
            i += 2;
        }
        i = 2;
        while (i <= m)
        {
            cout << i << " ";
            i += 2;
        }
    }
    else if (m == 1)
    {
        cout << 1;
    }
}