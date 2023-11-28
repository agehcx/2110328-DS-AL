#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e, k; cin >> n >> e >> k;
    vector<int> v[n];
    for (int i = 0; i < e; i++) {
        int u, w; cin >> u >> w;
        v[u].push_back(w);
        v[w].push_back(u);
    }
    int mxn = 0;
    for (int i = 0; i <n; i++) {
        int cnt = 0;
        vector<bool> vis(n, false);
        queue<pair<int,int>> q;
        q.push({i,1});
        while (!q.empty()) {
            auto & [t,c] = q.front();
            q.pop();

            cnt = max(cnt, c);
            
            if (vis[t]) continue;
            vis[t] = true;
            
            for (auto& it : v[t]) {
                if (!vis[it]) q.push({it, c + 1});
            }
        }
        mxn = max(mxn, cnt);

    }
    std::cout << mxn;
}