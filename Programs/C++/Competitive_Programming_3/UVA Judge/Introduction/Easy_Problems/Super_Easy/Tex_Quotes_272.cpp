#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char input[1000000] ="";
    bool open = 0;
    while(cin.getline(input, 100))
    {
        for(auto i : input)
        {
            if(i == '"' && open == 0)
            {
                cout << "``";
                open = 1;
            }
            else if (i == '"' && open == 1)
            {
                cout << "\'\'";
                open = 0;
            }
            else if(i == '\0')
            {
                continue;
            }
            else
            {
                cout << i;
            }
        }
        cout << "\n";
        memset(input, 0, sizeof(input));
    }
    return 0;
}
