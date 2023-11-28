#include <bits/stdc++.h>
using namespace std;

const int Nah = 1e6 + 7;
vector<vector<int>> vec(Nah);
vector<bool> vis(Nah, false);

int dfs(int u, int p, int cnt) {
    vis[u] = true;
    for (auto& it : vec[u]) {
        if (!vis[it]) {
            cout << "dbg\n";
            // return dfs(it, u, cnt + 1);
        } else {
            if (it != p) {
                cout << "THE HELL\n";
                return cnt;
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int u, v; cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int mx = 0;
    mx = dfs(0, -1, 1);
    cout << mx;
}