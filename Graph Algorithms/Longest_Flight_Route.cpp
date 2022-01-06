#include <bits/stdc++.h>

using namespace std;

#define N 100002
#define MOD 1000000007
#define MOD2 998244353
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(12);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '"' << x << '"';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]" << endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

const double PI = 3.1415926535897932384626;
const ll oo = 1e18;
const ll sz = N;

int n, m, a, b;
vi adj[sz], dist, to;
vb vis;

int dfs(int ver) {
    if(dist[ver] != -1) return dist[ver];
    if(vis[ver]) return dist[ver];

    vis[ver] = 1;
    if(ver == n) {
        dist[ver] = 1;
        to[ver] = 0;
        return 1;
    }

    for(auto &ed : adj[ver]) {
        if(dist[ed] == -1) dfs(ed);
        if(dist[ed] != -1 && dist[ed] + 1 > dist[ver]) {
            dist[ver] = dist[ed] + 1;
            to[ver] = ed;
        }
    }
    return dist[ver];
}

void solution(ll testno) {
    cin >> n >> m;
    fo(i,0,m) {
        cin >> a >> b;
        adj[a].pb(b);
    }
    to.resize(n + 1, -1);
    dist.resize(n + 1, -1);
    vis.resize(n + 1, 0);
    dfs(1);

    if(dist[1] <= 0) {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << dist[1] << endl;
    int x = 1;
    while(x > 0) {
        cout << x << " ";
        x = to[x];
    }
}

signed main()
{
    fastIO;
    ll test = 1;
    // cin >> test;
    fo(i, 1, test + 1) {
        solution(i);
        cout << endl;
    }
    return 0;
}