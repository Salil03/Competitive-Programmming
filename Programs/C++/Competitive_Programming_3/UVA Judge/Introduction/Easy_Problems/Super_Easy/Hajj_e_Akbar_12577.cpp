#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string name = "";
    int counter = 0;
    while(cin >> name)
    {
        if(name == "*")
        {
            break;
        }
        counter++;
        if(name == "Hajj")
        {
            cout << "Case " << counter << ": Hajj-e-Akbar\n";
        }
        else
        {
            cout << "Case " << counter << ": Hajj-e-Asghar\n";
        }
    }
}
