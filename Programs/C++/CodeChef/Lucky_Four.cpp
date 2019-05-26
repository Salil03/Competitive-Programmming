#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    string number = "";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> number;
        cout << count(number.begin(), number.end(), '4') << "\n";
    }
}
