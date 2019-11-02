#include <bits/stdc++.h>
long long counts[1000001] = {0};
long long N, T, answer;

using namespace std;

int main()
{
    cin >> N >> T;
    long long *s = new long long[N];
    for (long long i = 0; i < N; ++i)
        cin >> s[i];

    sort(s, s + N);
    for (long long k = 2; k < (N - 1); ++k)
    {
        if (s[k] >= T)
            break; // to exit this loop (optional: to reduce time further)

        long long j = k - 1;
        for (long long i = 0; i < j; ++i)
        {
            if (s[i] + s[j] < T)
            {
                ++counts[s[i] + s[j]];
            }
            else
            {
                break; // to exit this loop (optional: to reduce time further)
            }
        }
        for (long long l = k + 1; l < N; ++l)
        {
            if ((T - (s[k] + s[l])) >= 0)
            {
                answer += counts[T - (s[k] + s[l])];
            }
            else
            {
                break; // to exit this loop (optional: to reduce time further)
            }
        }
    }
    cout << answer;
    return 0;
}