#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string i = "";
        cin >> i;
        if(i.length() == 5)
        {
            cout << 3 << "\n";
            continue;
        }
        int one = 0;
        int two = 0;
        if(i[0] == 'o')
        {
            one++;
        }
        else if(i[0] == 't')
        {
            two++;
        }
        if(i[1] == 'n')
        {
            one++;
        }
        else if(i[1] == 'w')
        {
            two++;
        }
        if(i[2] == 'e')
        {
            one++;
        }
        else if(i[2] == 'o')
        {
            two++;
        }
        if(one > two)
        {
            cout << 1 << "\n";
            continue;
        }
        else
        {
            cout << 2 << "\n";
            continue;
        }
    }
}
