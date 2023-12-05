#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, s; cin >> n >> e >> s;
    
    vector<tuple<int, int, int>> G(e);
    vector<int> dist(n, INF);
    dist[s] = 0;

    for (auto& [a, b, c] : G) cin >> a >> b >> c;

    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : G) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < e; i++) {
        auto [u, v, w] = G[i];
        if (dist[v] != INF && dist[u] + w < dist[v]) {
            cout << "-1";
            return 0;
        }
    }

    for (auto it : dist) cout << it << ' ';
}