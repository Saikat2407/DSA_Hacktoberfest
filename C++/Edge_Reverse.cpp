//Problem Link : https://codeforces.com/contest/1777/problem/E

//Solution
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <math.h>
#include <chrono>
#include <random>
 
#define int ll
 
using namespace std;
 
using ll = long long;
 
const ll inf = 1e8;
const ll mod = (int)1e9 + 7;
const int N = (int)2e5 + 7;
 
vector<pair<int, int>> g[N];
vector<int> st;
int used[N];
 
void dfs1(int v, int c) {
    used[v] = 1;
    for (auto [u, w] : g[v]) {
        if (w > c) continue;
        if (!used[u]) {
            dfs1(u, c);
        }
    }
    st.push_back(v);
}
 
void dfs2(int v, int c) {
    used[v] = 2;
    for (auto [u, w] : g[v]) {
        if (w > c) continue;
        if (used[u] != 2) {
            dfs2(u, c);
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].push_back({ u, -1 });
        g[u].push_back({ v, w });
    }
    int l = -1, r = 1e9 + 1;
    while (r > l + 1) {
        int m = (r + l) / 2;
        fill(used, used + n, 0);
        st.clear();
        for (int v = 0; v < n; v++) {
            if (!used[v]) {
                dfs1(v, m);
            }
        }
        dfs2(st.back(), m);
        bool ok = 1;
        for (int v = 0; v < n; v++) {
            ok &= used[v] == 2;
        }
        if (ok) r = m;
        else l = m;
    }
    if (r == 1e9 + 1) {
        cout << "-1\n";
    }
    else {
        cout << r << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
} 
