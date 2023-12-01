#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;
vector<int> vec[MXN];
vector<bool> vis(MXN, false);

int cnt = 0;
int res = 0;

bool chk = false;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    if (vec[u].size() > 2) {
        res++;
        chk = true;
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (vis[t]) continue;
            vis[t] = true;
            for (auto it : vec[t]) {
                if (!vis[it]) q.push(it);
            }
        }
    } else {
        for (auto& it : vec[u]) {
            if (it != u) {
                dfs(it);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, e; cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i);
            if (!chk) {
                cnt++;
            } else {
                chk = false;
            }
        }
    }
    cout << cnt;
}