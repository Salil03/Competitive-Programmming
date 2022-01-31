/***********************
*   Jay Prakash Mahto  *
*       JVJplus        *
************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define uset unordered_set
#define umap unordered_map
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define pb push_back
#define NL cout << endl;
#define EL cerr << endl;
#define For(i, b) for (int i = 0; i < b; i++)
#define FoR(i, a, b) for (int i = a; i >= b; i--)
#define For1(i, b) for (int i = 1; i <= b; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define forit(v, c) for (auto v : c)
#define whileNE(x) while (!x.empty())
#define present(c, x) ((c).find(x) != (c).end())
#define cntbit __builtin_popcountll
#define REMAX(a, b) (a) = max((a), (b)) // set a to the maximum of a and b
#define REMIN(a, b) (a) = min((a), (b));
#define sz(a) (int)(a.size())

// directions
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//exponentiation
ll inline ipow(ll a, ll b, ll m)
{
    ll val = 1;
    a %= m;
    while (b)
    {
        if (b & 01)
            val = (val * a) % m;
        b >>= 1;
        a = (a * a) % m;
    };
    return val % m;
}
ll inline ipow(ll a, ll b)
{
    ll val = 1;
    while (b)
    {
        if (b & 01)
            val = (val * a);
        b >>= 1;
        a = (a * a);
    };
    return val;
}

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define all(a) a.begin(), a.end()

#define display2(x, y) cout << x << " " << y << endl;
#define accept_arr For(i, n) cin >> arr[i];
#define accept_array(arr, _n) For(i, _n) cin >> arr[i];
#define display1d(arr, length)       \
    for (int i = 0; i < length; i++) \
        cout << arr[i] << " ";       \
    cout << '\n';
#define display1D(arr, start, length)    \
    for (int i = start; i < length; i++) \
        cout << arr[i] << " ";           \
    cout << '\n';
#define display2d(arr, n)                       \
    For(i, n)                                   \
    {                                           \
        For(j, n) { cout << arr[i][j] << " "; } \
        cout << endl;                           \
    }
#define display2D(arr, m, n)                    \
    For(i, m)                                   \
    {                                           \
        For(j, n) { cout << arr[i][j] << " "; } \
        cout << endl;                           \
    }
#define gets(n)      \
    getline(cin, n); \
    cin.ignore();
#define input_array \
    cin >> n;       \
    For(i, n) cin >> arr[i];
#define input_array1 \
    cin >> n;        \
    FOR(i, 1, n)     \
    cin >> arr[i];

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define dbg(...) __dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __dbg(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __dbg(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __dbg(comma + 1, args...);
}

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    srand(time(NULL));
#define TCase             \
    int ___T, case_n = 1; \
    cin >> ___T;          \
    while (___T-- > 0)

#define N 10004
//vi g[N];
//bool visited[N];
//beware of global uses
int n, k, arr[N];

int dp[2][N][110];

void init()
{
}

int f(int prevAdded, int i, int k)
{
    if (i >= n || k <= -1)
    {
        return -INF;
    }
    if (i == n - 1)
    {
        if (k && arr[i] < 0) //last value is -ve than skip it if possible
            return 0;
        return arr[i];
    }

    if (dp[prevAdded][i][k] != -INF)
        return dp[prevAdded][i][k];

    int ans;
    if (prevAdded)
    {
        if (k == 0)
        {
            int o1 = arr[i] + f(1, i + 1, 0);
            int o2 = arr[i]; //make the segment end
            ans = max(o1, o2);
        }
        else
        {
            int o1 = f(1, i + 1, k - 1);
            int o2 = arr[i] + f(1, i + 1, k);
            ans = max(o1, o2);
        }
    }
    else
    {
        if (k == 0)
        {
            int o1 = f(0, i + 1, 0);
            int o2 = arr[i] + f(1, i + 1, 0);
            ans = max(o1, o2);
        }
        else
        {
            int o1 = f(0, i + 1, k);
            int o2 = arr[i] + f(1, i + 1, k);
            ans = max(o1, o2);
        }
    }
    return dp[prevAdded][i][k] = ans;
}

void solve()
{
    cin >> n >> k;
    For(i, n) cin >> arr[i];

    //fill dp
    For(i, 2)
    {
        For(j, N)
        {
            For(k, 102)
            {
                dp[i][j][k] = -INF;
            }
        }
    }

    k = 3;
    cout << f(0, 0, k) << endl;
    /*For(i,10)
        dbg(i,f(0,0,i));*/
}

int main()
{

    fast_io;

    // int t; cin>>t; while(t--)
    {
        init();
        solve();
    }
}