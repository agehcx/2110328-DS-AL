#include <bits/stdc++.h>
using namespace std;

/*
50 / 100
PPPPPTTTTT
*/

const int MXN = 21;
int adj[MXN][MXN] = {0};
vector<bool> visited(MXN, false);
vector<bool> pathFound(8, false);
vector<pair<int, int>> vec[MXN];
int n, m;

struct ComparePairs {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);
    }
};

void dfs(int dist, int u, int targetSum, int idx) {
    if (dist == targetSum) {
        pathFound[idx] = true;
        return;
    }

    visited[u] = true;

    for (auto& [v, w] : vec[u]) {
        if (dist + w <= targetSum && !visited[v]) {
            dfs(dist + w, v, targetSum, idx);
        }
    }

    visited[u] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<int> res(8);
    for (auto& e : res) cin >> e;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = w;
        adj[b][a] = w;
        vec[a].push_back({b, w});
        vec[b].push_back({a, w});
    }

    for (int i = 0; i < n; i++) {
        std::sort(vec[i].begin(), vec[i].end(), ComparePairs());
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < n; j++) {
            fill(visited.begin(), visited.end(), false);
            dfs(0, j, res[i], i);
        }
    }

    for (bool found : pathFound) {
        cout << (found ? "YES\n" : "NO\n");
    }
}
