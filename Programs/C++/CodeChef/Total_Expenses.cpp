#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, p;
        double t;
        scanf("%d%d", &n, &p);
        t = n * p;
        if (n > 1000)
            t -= t * 0.1;

        printf("%.6lf\n", t);
    }
}
