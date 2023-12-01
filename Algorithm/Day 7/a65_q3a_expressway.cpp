#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int MXN = 703;
vector<pi> g[MXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, g12; cin >> N >> g12;
    g[1].push_back({2, g12});
    for (int i = 3; i <= N; i++) {
        int K; cin >> K;
        for (int j = 0; j < K; j++) {
            int u, v; cin >> u >> v;
            g[i].push_back({u, v});
            g[u].push_back({i, v});
        }
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> dist(i + 1, INT_MAX);
        vector<bool> vis(i + 1, false);

        pq.push({0,1});

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto [nx, nw] : g[u]) {
                if (dist[nx] > w + nw) {
                    dist[nx] = w + nw;
                    pq.push({dist[nx], nx});
                }
            }
        }
        cout << dist[2] << ' ';
    }
}