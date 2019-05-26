#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n = 0, temp = 0;
    cin >> n;
    vector<long long> s;
    for (long long i = 0; i < n; i++)
    {
        cin >> temp;
        s.push_back(temp);
    }
    temp = 0;
    sort(s.begin(), s.end());
    for (long long i = 0; i < s.size(); i++)
    {
        temp += s[i] * (i - (n - 1 - i));
    }
    cout << temp;
}