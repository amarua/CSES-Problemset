#include <bits/stdc++.h>

using namespace std;

#define N 100002
#define MOD 1000000007
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

ll n, m, k, a, b, w;

void solution(ll testno) {
    cin >> n >> m >> k;
    vector<vector<pll>> adj(n + 1);
    fo(i,0,m) {
        cin >> a >> b >> w;
        adj[a].pb({b, w});
    }
    
    vector<priority_queue<ll>> best(n + 1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    best[1].push(0);

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if(p.fi > best[p.se].top()) continue;

        for(auto &ed : adj[p.se]) {
            ll dist = p.fi + ed.se;
            if(best[ed.fi].size() < k) {
                best[ed.fi].push(dist);
                pq.push({dist, ed.fi});
            }
            else if(best[ed.fi].top() > dist) {
                best[ed.fi].pop();
                best[ed.fi].push(dist);
                pq.push({dist, ed.fi});
            }
        }
    }

    vll res;
    while(!best[n].empty()) {
        res.pb(best[n].top());
        best[n].pop();
    }
    reverse(all(res));
    for(auto &x : res) cout << x << " ";
}

signed main()
{
    fastIO;
    ll test = 1;
    // cin >> test;
    fo(i, 1, test + 1)
        solution(i);
    return 0;
}