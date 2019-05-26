#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0, score = 0, a = 0, b = 0, a_temp = 0, b_temp = 0;
    bool winner = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        a += a_temp;
        b += b_temp;
        a_temp = a;
        b_temp = b;
        if (a > b)
        {
            if (a - b > score)
                score = a - b;
            winner = 0;
        }
        else if (b - a > score)
        {
            score = b - a;
            winner = 1;
        }
    }
    cout << winner + 1 << " " << score;
}