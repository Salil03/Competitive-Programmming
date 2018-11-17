#include <bits/stdc++.h>
using namespace std;
int sum_digit(int no)
{
    return no == 0 ? 0 : no % 10 + sum_digit(no / 10);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n = 0, t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << sum_digit(n) << "\n";
    }
}