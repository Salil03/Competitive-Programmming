#include <bits/stdc++.h>
using namespace std;

void Process(vector<vector<long>> &A, int n, int m)
{
    A[0][0] = 1;
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j > 0; j--)
            for (int k = i; k < m; k++)
                A[j][k] += A[j - 1][k - i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long T, t = 1;
    cin >> T;
    int n, m;
    n = 53;
    m = 1379;
    vector<vector<long>> DP(n, vector<long>(m, 0));
    Process(DP, n, m);
    while (t <= T)
    {
        long ans, L, S;
        cin >> L >> S;
        if (L >= n || S >= m)
        {
            ans = 0;
        }
        else
        {
            ans = DP[L][S];
        }
        cout << "Case " << t << ": " << ans << endl;
        t++;
    }
    return 0;
}