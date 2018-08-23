#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n = 0;
    cin >> n;
    long long temp = 0;
    vector<long long> numbers;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
    vector<long long> final;
    for (int i = 0; i < numbers.size(); i++)
    {
        final.push_back(numbers[i] * (n - i));
    }
    cout << *max_element(final.begin(), final.end());
}