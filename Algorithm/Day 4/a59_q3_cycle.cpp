#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;
vector<int> vec[MXN];
bool vis[MXN] = {false};
int res[MXN] = {0};

int ans = -1;

void dfs(int prev, int u, int cnt) {
    vis[u] = 1;
    res[u] = cnt;
    for (auto it : vec[u]) {
        if (it != prev && ans == -1) {
            if (res[it] == -1) {
                dfs(u, it, cnt + 1);
            } else {
                ans = cnt - res[it] + 1;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V; cin >> V;
    for (int i = 0; i < V; i++) {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        res[i] = -1;
    }
    dfs(-1, 0, 0);
    cout << ans;
}
