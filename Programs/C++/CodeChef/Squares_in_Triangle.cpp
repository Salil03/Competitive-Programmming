#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    int b = 0;
    while (t--)
    {
        cin >> b;
        cout << b / 2 * (b / 2 - 1) / 2 << "\n";
    }
}