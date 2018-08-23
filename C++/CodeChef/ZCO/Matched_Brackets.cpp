#include <iostream>
using namespace std;
int i = 1, temp_st = 0, max1 = 0, max_pos = 0, n, temp;
int max_cnt = 0, max1_pos = 0, temp_cnt = 0, temp_pos = 0, cnt = 0;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> temp;
        if (temp == 1)
        {
            temp_cnt++;
            if (cnt == 0)
                temp_cnt = 1, temp_pos = i;
            temp_st++;
            if (max1 < temp_st)
                max1 = temp_st, max_pos = i;
            cnt++;
        }
        else
        {
            temp_cnt++;
            if (cnt == 0)
                temp_cnt = 1, temp_pos = i;
            temp_st--;
            cnt--;
        }

        if (max_cnt < temp_cnt)
            max_cnt = temp_cnt, max1_pos = temp_pos;

        ++i;
    }
    cout << max1 << " " << max_pos << " " << max_cnt << " " << max1_pos << endl;
}