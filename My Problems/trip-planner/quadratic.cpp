#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (auto i{a}; i < (b); ++i)
#define all(x) (x).begin(), (x).end()

constexpr int mod = 1e9 + 7;

void inc(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

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

    rep(i, 0, m) {
        rep(b, 0, 2) {
            int acc = 0;
            for (int z = 1; z <= n; ++z) inc(acc, f[b][z]);

            fill(all(g[b]), acc);
            for (int x = 1; x <= n; ++x)
                for (int z = 1; z <= n; ++z)
                    if (gcd(x, z) == 1) inc(g[b][x], f[!b][z]);
        }

        swap(f, g);
    }

    return f[1][s];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    while (t--) cout << solve() << '\n';
}
