#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, h = 0, temp = 0;
    cin >> n >> h;
    vector<int> boxes;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        boxes.push_back(temp);
    }
    auto it = boxes.begin();
    bool crane = false;
    while (cin >> temp)
    {
        if (temp == 1)
        {
            if (it != boxes.begin())
            {
                it--;
            }
        }
        else if (temp == 2)
        {
            if ((it != boxes.end()) && (it != boxes.end() - 1))
            {
                it++;
            }
        }
        else if (temp == 3)
        {
            if ((boxes[it - boxes.begin()] > 0) && (crane == false))
            {
                boxes[it - boxes.begin()]--;
                crane = true;
            }
        }
        else if (temp == 4)
        {
            if ((boxes[it - boxes.begin()] < h) && (crane == true))
            {
                boxes[it - boxes.begin()]++;
                crane = false;
            }
        }
        else if (temp == 0)
        {
            for (int i : boxes)
            {
                cout << i << " ";
            }
        }
    }
}