#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int counter = 0;
    while(cin >> n)
    {
        if(n == 0)
        {
            return 0;
        }
        counter++;
        int temp, given=0, togive=0;
        while(n--)
        {
            cin >> temp;
            if(temp == 0)
            {
                given++;
            }
            else
            {
                togive++;
            }
        }
        cout << "Case " << counter <<": " << togive - given << "\n";
    }
}
