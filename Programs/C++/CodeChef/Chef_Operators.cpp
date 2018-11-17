#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 0, a = 0, b = 0;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a > b)
        {
            cout << ">\n";
        }
        if (a < b)
        {
            cout << "<\n";
        }
        if (a == b)
        {
            cout << "=\n";
        }
    }
}