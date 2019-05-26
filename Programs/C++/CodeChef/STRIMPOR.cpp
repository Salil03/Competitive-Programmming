#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n, int k)
{
    int temp;
    vector<pair<int, int>> v;
    for (int i = 0; i < n-2; ++i)
    {
        if (arr[i] == 5)
        {
            for (int j = i + 2; j < n;j+= 3)
            {
                if (arr[j] == 7)
                {
                    temp = (j - i) +1;
                    v.push_back(make_pair(i, j));
                }
            }
        }
    }
    int b, e, min = INT_MAX,st,en;
    --k;
    int count = 0;
    for (int b = 0;b < n - k;++b){
        e = b + k;
        for (int i = 0; i < v.size(); ++i)
        {
            st = v[i].first;
            en = v[i].second;
            if ((st <= b && en >= b) || (st <= e && en >= e))
            {
                ++count;
            }
        }
        if (count < min) {
            min = count;
        }
        count  = 0;
    }

    cout << min << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, k;
        cin >> n >> k;
        char s;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (s == 'X')
            {
                arr[i] = 5;
            }
            if (s == 'Y')
            {
                arr[i] = 6;
            }
            if (s == 'Z')
            {
                arr[i] = 7;
            }
        }
        solve (arr,n,k);
    }
}