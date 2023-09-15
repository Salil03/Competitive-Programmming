#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (auto i{a}; i < (b); ++i)
#define all(x) (x).begin(), (x).end()

constexpr int mod = 1e9 + 7;
void inc(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

constexpr int N = 1e4 + 10;
int8_t mu[N];
bool sieve[N];

int solve() {
    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;

    /*
     * f[m + 1][b][x][y] = sum(f[m][b][z][y] | z)
     *                     + sum(f[m][!b][z][y] | z : gcd(z, x) = 1)
     *
     * f[0][y][y] = 1
     * f[0][x][y] = 0 otherwise
     */

    array<vector<int>, 2> f, g;
    rep(b, 0, 2) {
        f[b].assign(n + 1, 0);
        g[b].assign(n + 1, 0);
    }
    f[0][t] = 1;

    /*
     *      g(x) = sum(f(z) | z : gcd(x, z) = 1)
     * <=>  g(x) = sum(
     *                 mu(d) * sum(f(z) | z : d divides z) |
     *                 d : d divides x)
     */
    rep(i, 0, m) {
        rep(b, 0, 2) {
            int acc = 0;
            for (int z = 1; z <= n; ++z) inc(acc, f[b][z]);

            fill(all(g[b]), acc);
            for (int d = 1; d <= n; ++d) {
                if (mu[d] == 0) continue;

                int inner = 0;
                for (int z = d; z <= n; z += d) inc(inner, f[!b][z]);
                if (mu[d] == -1) inner = mod - inner;

                for (int x = d; x <= n; x += d) inc(g[b][x], inner);
            }
        }

        swap(f, g);
    }

    return f[1][s];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    fill(mu, mu + N, 1);
    rep(i, 2, N) {
        if (sieve[i]) continue;
        mu[i] = -1;
        for (auto j = 2 * i; j < N; j += i) sieve[j] = true, mu[j] = -mu[j];
        const auto sq = (int64_t)i * i;
        for (auto j = sq; j < N; j += sq) mu[j] = 0;
    }

    int t=1;
    while (t--) cout << solve() << '\n';
}
