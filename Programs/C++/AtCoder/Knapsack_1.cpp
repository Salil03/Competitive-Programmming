#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 105, MAXV = 100005;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll dp[MAXV];
ll weight[MAXN];
ll value[MAXN];
int object_count, max_weight;

void solve() {
    for (int v = 1; v < MAXV; ++v) dp[v] = inf;
    for (int i = 1; i <= object_count; ++i) {
        for (int v = MAXV - 1; v >= value[i]; --v) {
            dp[v] = min(dp[v], dp[v - value[i]] + weight[i]);
        }
    }
}

int main() {
    scanf("%d%d", &object_count, &max_weight);
    for (int i = 1; i <= object_count; ++i) {
        scanf("%lld%lld", weight + i, value + i);
    }
    solve();
    for (int v = MAXV - 1; ~v; --v) {
        if (dp[v] && dp[v] <= max_weight) {
            printf("%d\n", v);
            return 0;
        }
    }
}
