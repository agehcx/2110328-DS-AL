#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;

    vector<int> v[n], hk(k), ct(n), dist(n, 1e9 + 7);

    for (auto& e : hk) cin >> e;
    for (auto& e : ct) cin >> e;

    for (int i = 0; i < m; i++) {
        int u, w; cin >> u >> w;
        v[u].push_back(w);
        v[w].push_back(u);
    }

    priority_queue<int> pq;
    for (auto& e : hk) {
        dist[e] = ct[e];
        pq.push(e);
    }

    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        for (auto it : v[u]) {
            if (dist[it] > dist[u] + ct[it]) {
                dist[it] = dist[u] + ct[it];
                pq.push(it);
            }
        }
    }

    cout << *max_element(dist.begin(), dist.end());
}