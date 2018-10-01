#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        int l = str.length();
        if (l % 2 == 0)
        {
            int hash[26] = {0};
            for (int i = 0; i < l; i++)
            {
                hash[str[i] - 'a']++;
            }
            int d = 0;
            int flag = 0;
            for (int j = 0; j < 26; j++)
            {

                if (hash[j] % 2 != 0)
                {
                    flag = 1;
                    d++;
                }
            }
            if (flag == 1)
                cout << d - 1 << "\n";
            else
                cout << d << "\n";
        }
        else
        {
            int hash[26] = {0};
            for (int i = 0; i < l; i++)
            {
                hash[str[i] - 'a']++;
            }
            int d = 0;
            int flag = 0;
            for (int j = 0; j < 26; j++)
            {

                if (hash[j] % 2 != 0)
                {

                    d++;
                }
            }

            cout << d - 1 << "\n";
        }
    }
}