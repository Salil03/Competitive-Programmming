#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> arr;
    int temp;
    for(int i=0; i < n+m; i++)
    {
        cin >> temp;
        if(temp != -1)
        {
            arr.push_back(temp);
        }
        else
        {
            cout << *max_element(arr.begin(), arr.end()) << "\n";
            arr.erase(remove(arr.begin(), arr.end(), *max_element(arr.begin(), arr.end())), arr.end());
        }
    }
}
