#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int temp;
    for(int i =0; i< t; i++)
    {
        cin >> temp;
        if(temp > 20)
        {
            cout << "Case " << i+1 << ": bad\n";
            cin >> temp;
            cin >> temp;
            continue;
        }
        cin >> temp;
        if(temp > 20)
        {
            cout << "Case " << i+1 << ": bad\n";
            cin >> temp;
            continue;
        }
        cin >> temp;
        if(temp > 20)
        {
            cout << "Case " << i+1 << ": bad\n";
            continue;
        }
        cout << "Case " << i+1 << ": good\n";
    }
}
