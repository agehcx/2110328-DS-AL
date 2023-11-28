#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int p, vector<bool>& vis, vector<vector<int>>& vec) {
    vis[u] = true;
    for (auto& it : vec[u]) {
        if (!vis[it]) {
            if (dfs(it, u, vis, vec)) return true;
        } else {
            if (it != p) return true;
        }
    }
    return false;
}

void solve() {
    int N, E; cin >> N >> E;
    bool hasCyc = false;
    vector<vector<int>> vec(N);
    vector<bool> vis(N, false);
    for (int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, vis, vec)) {
                hasCyc = true;
                break;
            }
        }
    }

    cout << (hasCyc ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    while (Q--) solve();
}