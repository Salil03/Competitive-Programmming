#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n =0;
    cin >> n;
    int temp;
    set<int> numbers;
    while(n--)
    {
        cin >> temp;
        numbers.insert(temp);
    }
    for(int i : numbers)
    {
        cout << i << " ";
    }
}
