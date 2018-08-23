#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    if (n == 2)
    {
        int temp = 0;
        cin >> temp;
        cout << 1;
    }
    vector<int> numbers;
    for (int i = 1; i < n; i++)
    {
        int m = 0;
        cin >> m;
        numbers.push_back(m);
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < (numbers.size() - 1); i++)
    {
        if ((numbers[i + 1] - numbers[i]) != 1)
        {
            cout << (numbers[i] + 1);
        }
    }
}