#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    float y;
    cin >> x >> y;
    if ((int(x) % 5 != 0) || (y < x + 0.50))
    {
        cout << y;
    }
    else
    {
        cout << y - x - 0.50;
    }
}