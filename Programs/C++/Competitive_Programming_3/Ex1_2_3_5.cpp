#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int day[n];
    int month[n];
    int year[n];
    for (int i = 0; i < n; i++)
    {
        cin >> day[i] >> month[i] >> year[i];
    }
    int arr_month[n];
    int arr_day[n];
    copy(month, month + n, arr_month);
    copy(day, day + n, arr_day);
    sort(arr_month, arr_month + n);
    sort(arr_day, arr_day + n);
    for (int i : arr_month)
    {
        cout << i;
    }
    for (int i : arr_day)
    {
        cout << i;
    }
    int age[n];
    for (int i = 0; i < n; i++)
    {
        age[i] = day[i] + month[i] * 30 + year[i] * 365;
    }
    sort(age, age + n);
    for (int i : age)
    {
        cout << i;
    }
}