#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int hard[N];
int freq[N];

int get(int l, int r)
{
    return freq[r] - freq[l - 1];
}

int main()
{
    //freopen("in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        hard[p]++;
    }
    freq[0] = hard[0];
    for (int i = 1; i <= k; i++)
        freq[i] = freq[i - 1] + hard[i];
    long long cnt = 0;
    int l = 1, r = k - 1;
    for (int i = 0; i < k / 2; i++)
    {
        cnt += hard[i] * 1LL * get(l, r);
        //cout << i << " " << hard[i] << " " << l << " " << r << " " << get(l,r) << endl;
        l++;
        r--;
    }
    for (int i = 0; i < k / 2; i++)
    {
        if (hard[i] <= 1)
            continue;
        cnt += (hard[i] * 1LL * (hard[i] - 1)) / 2;
    }
    cout << cnt << endl;
}