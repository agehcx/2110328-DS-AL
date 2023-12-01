#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e4 + 3;
vector<int> v[MXN];
vector<bool> vis(MXN, false);

int n, e, k;

void dfs(int u, int cnt) {
    if (cnt == k) return;
    for (auto it : v[u]) {
        vis[it] = 1;
        dfs(it, cnt + 1);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> e >> k;
    for (int i = 0; i < e; i++) {
        int u, w; cin >> u >> w;
        v[u].push_back(w);
        v[w].push_back(u);
    }
    int mxn = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        vis[i] = 1;
        dfs(i, 0);
        for (int j = 0; j < n; j++) {
            if (vis[j]) {
                vis[j] = false;
                cnt++;
            }
        }
        mxn = max(mxn, cnt);
    }
    std::cout << mxn;
}