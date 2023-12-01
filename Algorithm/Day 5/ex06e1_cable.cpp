#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e3 + 7;
vector<int> parent(MXN, -1);

int fp(int u) {
    if (parent[u] == -1) return u;
    return parent[u] = fp(parent[u]);
}

void du(int u, int v) {
    int rootU = fp(u);
    int rootV = fp(v);
    parent[rootU] = rootV;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    
    vector<pair<int, pair<int, int>>> g;

    for (int i = 0; i < n - 1; i++) {
        parent[i] = -1;
        for (int j = i + 1; j < n; j++) {
            int x; cin >> x;
            g.push_back({x, {i, j}});
        }
    }
 
    sort(g.begin(), g.end(), less<pair<int, pair<int, int>>>());

    long long res = 0;

    for (auto it : g) {
        int u = fp(it.second.first);
        int v = fp(it.second.second);
        if (u != v) {
            res += it.first;
            du(u, v);
        }
    }

    cout << res;
}