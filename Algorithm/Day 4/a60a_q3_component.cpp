#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, e; cin >> v >> e;
    vector<int> vec[v+1];
    for (int i = 0; i < e; i++) {
        int u, w; cin >> u >> w;
        vec[u].push_back(w);
        vec[w].push_back(u);
    }
    vector<bool> vis(v+1, false);
    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        queue<int> q;
        if (!vis[i]) {
            q.push(i);
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                if (vis[t]) continue;
                vis[t] = true;
                for (auto& it : vec[t]) {
                    if (!vis[it]) q.push(it);
                }
            }
            cnt++;
        }
    }
    cout << cnt;

}