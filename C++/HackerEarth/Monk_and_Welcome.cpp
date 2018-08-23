#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, temp = 0;
    cin >> n;
    deque<int> a;
    deque<int> b;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    for (auto it_a = a.begin(), it_b = b.begin(); it_a != a.end() && it_b != b.end(); it_a++, it_b++)
    {
        cout << *it_a + *it_b << " ";
    }
}