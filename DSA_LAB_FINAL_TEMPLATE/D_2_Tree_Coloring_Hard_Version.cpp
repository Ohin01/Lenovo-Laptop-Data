#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename dataType>
using ordered_set = tree<dataType, null_type, less<dataType>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename dataType1, typename dataType2>
using ordered_map = tree<dataType1, dataType2, less<dataType1>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename dataType>
using ordered_multiset = tree<dataType, null_type, less_equal<dataType>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef long long       ll;
typedef long double     ld;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<ll>      vll;
typedef vector<vll>     vvll;
typedef vector<bool>    vb;
typedef vector<vb>      vvb;
typedef pair<int, int>  pi;
typedef vector<pi>      vpi;
typedef pair<ll, ll>    pll;
typedef vector<pll>     vpll;

#define pb              push_back
#define ff              first
#define ss              second
#define index           find_by_order
#define FOR(i, a, b)    for(ll i = (a); i < (b); i++)
#define FORR(i, a, b)    for(ll i = (a); i >= (b); i--)
#define YES             cout << "YES\n"
#define NO              cout << "NO\n"
#define lcm(a, b)       ((a / __gcd(a, b)) * b)
 
const ll MOD = 1e9 + 7;//998244353;
const ll INF = 9e18;
const ld PI = acos((ld) -1);
const int MAX = 2e5 + 5;
const int MX = 1e6 + 5;

ll Bigmod(ll a, ll b, ll m){
    if(b == 0) return 1 % m;
    ll x = Bigmod(a, b / 2LL, m);
    x = (x * x) % m;
    if(b % 2 == 1) x = (x * a) % m;
    return x;
}

ll fact[MX];
ll inv[MX];
vpll mv = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void pre(){
    fact[0]=1;
    inv[0]=1;
    FOR(i, 1, MX){
        fact[i] = (i * fact[i - 1])% MOD;
        inv[i] = Bigmod(fact[i], MOD - 2LL, MOD);
    }
}

ll nCr(ll n, ll r, ll p) { 
    if(r > n || r < 0) return 0;
    if(n == r || r == 0) return 1;
    return (((fact[n] * inv[r]) % p ) * inv[n - r]) % p;
}

vvll graph(MAX);
vll depth(MAX);
vll par(MAX, 0);

void dfs(ll node, ll parent)
{
    for (auto child: graph[node])
    {
        if (child == parent) continue;

        par[child] = node;
        depth[child] = depth[node] + 1;

        dfs(child, node);
    }
}

void solve()
{
    ll n;
    cin >> n;

    FOR(i, 1, n + 1)
    {
        graph[i].clear();
        depth[i] = 0;
        par[i] = 0;
    }

    FOR(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;

        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, 0);

    vvll alldepth(n + 1);

    ll mx = -1;

    FOR(i, 1, n + 1)
    {
        mx = max(mx, depth[i]);
        alldepth[depth[i]].pb(i);
    }

    ll ans = -1;
    ll val = -1;

    FOR(i, 0, mx + 1)
    {
        ans = max(ans, (ll)alldepth[i].size());
    }

    FOR(i, 0, mx + 1)
    {
        if (alldepth[i].size() == ans)
        {
            vll arr;

            FOR(j, 0, alldepth[i].size())
            {
                arr.pb(alldepth[i][j]);
            }

            unordered_set<ll, custom_hash> cnt;

            FOR(j, 0, arr.size())
            {
                cnt.insert(par[arr[j]]);
            }

            if (cnt.size() == 1)
            {
                ans++;
                break;
            }
        }
    }

    vector<stack<int>> st(n + 1);


    FOR(i, 1, n + 1)
    {
        for (auto child: graph[i])
        {
            if (child != par[i]) st[i].push(child);
        }
    }

    vll chCount(n + 1);

    FOR(i, 1, n + 1)
    {
        chCount[i] = st[i].size();
    }

    priority_queue<pair<ll, ll>> pq;

    vll color(n + 1);
    ll c = 1;

    FORR(i, mx, 0)
    {
        vpll pr;

        FOR(j, 0, alldepth[i].size())
        {
            pr.pb({chCount[alldepth[i][j]], alldepth[i][j]});
        }

        sort(pr.begin(), pr.end());

        FOR(j, 0, pr.size())
        {
            ll node = pr[j].ss;

            if (!pq.empty())
            {
                pll f = pq.top();
                pq.pop();

                if (f.ss == node)
                {
                    if (!pq.empty())
                    {
                        pll s = pq.top();
                        pq.pop();

                        ll parr = s.ss;

                        ll chose = st[parr].top();
                        st[parr].pop();
                        color[node] = color[chose];

                        s.ff--;

                        if (s.ff != 0)
                        {
                            pq.push(s);
                        }

                        pq.push(f);
                    }

                    else
                    {
                        color[node] = c;
                        c++;
                        pq.push(f);
                    }
                }

                else
                {
                    ll parr = f.ss;

                    ll chose = st[parr].top();
                    st[parr].pop();
                    color[node] = color[chose];

                    f.ff--;

                    if (f.ff != 0)
                    {
                        pq.push(f);
                    }
                }

            }

            else
            {
                color[node] = c;
                c++;
            }
        }

        if (i == 0)
        break;

        FOR(j, 0, alldepth[i - 1].size())
        {
            ll node = alldepth[i - 1][j];

            if (chCount[node] != 0) 
            pq.push({chCount[node], node});

        }
    }

    vvll prnt(ans + 1);

    FOR(i, 1, n + 1)
    {
        prnt[color[i]].pb(i);
    }

    cout << ans << endl;

    FOR(i, 1, ans + 1)
    {
        cout << prnt[i].size() << " ";

        FOR(j, 0, prnt[i].size())
        {
            cout << prnt[i][j] << " ";
        }
        cout << endl;
    }


}

void solve2()
{
    ll n;
    cin >> n;

    FOR(i, 1, n + 1)
    {
        graph[i].clear();
        depth[i] = 0;
        par[i] = 0;
    }

    FOR(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;

        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, 0);

    vvll alldepth(n + 1);

    ll mx = -1;

    FOR(i, 1, n + 1)
    {
        mx = max(mx, depth[i]);
        alldepth[depth[i]].pb(i);
    }

    ll ans = -1;
    ll val = -1;

    FOR(i, 0, mx + 1)
    {
        ans = max(ans, (ll)alldepth[i].size());
    }

    FOR(i, 0, mx + 1)
    {
        if (alldepth[i].size() == ans)
        {
            vll arr;

            FOR(j, 0, alldepth[i].size())
            {
                arr.pb(alldepth[i][j]);
            }

            unordered_set<ll, custom_hash> cnt;

            FOR(j, 0, arr.size())
            {
                cnt.insert(par[arr[j]]);
            }

            if (cnt.size() == 1)
            {
                ans++;
                break;
            }
        }
    }

    deque<ll> dq;

    FOR(i, 1, ans + 1)
    {
        dq.push_back(i);
    }

    vll color(n + 1);
    color[1] = 1;

    FOR(i, 1, mx + 1)
    {
        FOR(j, 0, alldepth[i].size())
        {
            ll node = alldepth[i][j];
            
            ll cur = dq.front();
            dq.pop_front();

            if (cur == color[par[node]])
            {
                ll sec = dq.front();
                dq.pop_front();

                color[node] = sec;
                dq.push_back(cur);
                dq.push_back(sec);
                
            }

            else
            {
                color[node] = cur;
                dq.push_back(cur);
            }
        }
    }

    vvll prnt(ans + 1);

    FOR(i, 1, n + 1)
    {
        prnt[color[i]].pb(i);
    }

    cout << ans << endl;

    FOR(i, 1, ans + 1)
    {
        cout << prnt[i].size() << " ";

        FOR(j, 0, prnt[i].size())
        {
            cout << prnt[i][j] << " ";
        }
        cout << endl;
    }

    
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int cases = 1;
    cin >> cases;

    while (cases--)
    {
        solve();
    }
}