#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    float h,u,d,f;
    while(cin >> h >> u >> d >> f)
    {
        if(int(h) == 0)
        {
            break;
        }
        float distance = 0;
        int counter = 0;
        bool day = true;
        do
        {
            if(day == true)
            {
                if(u - u*counter*(f/100) < 0)
                {
                    counter++;
                    day = false;
                }
                else
                {
                    distance += u - u*counter*(f/100);
                    counter++;
                    day = false;
                }
            }
            else
            {
                distance -= d;
                day = true;
            }
        }
        while(distance <= h && distance >= 0);
        if(distance >= h)
        {
            cout << "success on day " << counter << "\n";
        }
        else if(distance <= 0)
        {
            cout << "failure on day " << counter << "\n";
        }
    }
}
