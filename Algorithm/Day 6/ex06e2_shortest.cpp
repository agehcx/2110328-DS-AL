#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e, s; cin >> n >> e >> s;
    vector<pair<int, int>> G[n];
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back({b, c});
        dist[a][b] = c;
    }

    vector<int> distance(n, INF);
    distance[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto edge : G[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (distance[u] != INF && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (distance[i] == -1) {
            cout << "-1";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << distance[i];
    }
}