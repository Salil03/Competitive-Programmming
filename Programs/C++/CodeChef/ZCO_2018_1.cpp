#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int c,n;
        bool k;
        int x,y;
        cin >> c >> n >> k;
        while(n--)
        {
            cin >> x >> y;
            c -= y-x+1;
        }
        if(c >-1)
        {
            cout << "Good\n";
        }
        else
        {
            cout << "Bad\n";
        }
    }
}