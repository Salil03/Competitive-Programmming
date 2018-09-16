#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    float a = 0, b = 0, c = 0;
    while (t--)
    {
        cin >> a >> b >> c;
        if (a + b + c == 180)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}