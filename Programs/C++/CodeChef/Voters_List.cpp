#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int total = n1 + n2 + n3;
    vector<int> initial;
    vector<int> voters;
    int x;
    while (total--)
    {
        cin >> x;
        initial.push_back(x);
    }
    sort(initial.begin(), initial.end());
    if (initial[0] == initial[1])
    {
        voters.push_back(initial[0]);
    }
    for (int i = 1; i < initial.size(); i++)
    {
        if ((initial[i - 1] != initial[i]) && (initial[i] == initial[i + 1]))
        {
            voters.push_back(initial[i]);
        }
    }
    cout << voters.size() << "\n";
    for (int k = 0; k < voters.size(); k++)
    {
        cout << voters[k] << "\n";
    }
}