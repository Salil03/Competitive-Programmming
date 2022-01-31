#include <bits/stdc++.h>

#define MOD 1000000007
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int dp[1000005][3], N;
ll A[1000005];

int f(int i, int state)
{
    if (i > N)
        return 0;
    else if (dp[i][state] != -1)
    {
        return dp[i][state];
    }
    else
    {
        if (i == N)
            dp[i][state] = 1;
        else if (state == 1 && A[i] > A[i + 1])
            dp[i][state] = 1;
        else if (state == 2 && A[i] < A[i + 1])
            dp[i][state] = 1;
        else if (state == 1 && A[i] <= A[i + 1])
            dp[i][state] = 1 + f(i + 1, 2);
        else if (state == 2 && A[i] >= A[i + 1])
            dp[i][state] = 1 + f(i + 1, 1);
        return dp[i][state];
    }
}

int main()
{

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);

    int T, i, x, ans;
    cin >> T;
    while (T--)
    {
        memset(dp, -1, sizeof dp);
        cin >> N;
        for (i = 1; i <= N; i++)
        {
            cin >> A[i];
        }
        for (i = 1; i <= N; i++)
        {
            x = f(i, 1);
            //cout<<i<<" "<<x<<" ";
            x = f(i, 2);
            //cout<<x<<"\n";
        }
        ans = -1;
        for (i = 1; i <= N; i++)
        {
            x = dp[i][1];
            if (i + x > N)
                ans = max(ans, dp[i][1] + 1);
            else if (x % 2 == 0)
                ans = max(ans, dp[i][1] + 1 + dp[i + x][2]);
            else if (x % 2 == 1)
                ans = max(ans, dp[i][1] + 1 + dp[i + x][1]);
        }
        cout << ans << "\n";
    }
    return 0;
}