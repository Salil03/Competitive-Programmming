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
        string s;
        cin >>s ;
        int a = 0;
        char winner = 'A';
        for(char i : s)
        {
            if(i == 'A' && a == 0)
            {
                a++;
            }
            else if(i=='A' && a == 1)
            {
                a--;
            }
            else if(i == 'A' && a == 2)
            {
                winner = 'B';
            }
            if(i == 'B' && a == 1)
            {
                a++;
            }
        }
        cout << winner << "\n";
    }
}