#include <bits/stdc++.h>
using namespace std;

int n, k;

int solve(vector<int> big, vector<int> small) {
    int ck = k;
    int smallPt = n - 1;
    int bigPt = 0;
    while (ck > 0) {
        if (big[bigPt] >= small[smallPt])
            break;
        else if(bigPt >= n || smallPt < 0)
            break;
        else {
            ck--;
            swap(big[bigPt], small[smallPt]);
            bigPt++;
            smallPt--;
        }
    }
    sort(big.begin(), big.end());
    sort(small.begin(), small.end());
    return big[n - 1] + small[n - 1];
}

int main() {
    vector<int> a, b;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout <<  min(solve(a, b), solve(b, a)) ;
    return 0;
}