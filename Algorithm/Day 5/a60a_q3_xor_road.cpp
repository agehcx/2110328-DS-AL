#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

const int MXN = 2e3 + 7;
vector<pair<ll, pl>> G;
vector<int> p(MXN, -1);

int fp(int u) {
    if (p[u] == -1) return u;
    return p[u] = fp(p[u]);
}

void du(int u, int v) {
    int rootU = fp(u);
    int rootV = fp(v);
    p[rootU] = rootV;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    ll val[N];
    for (int i = 0; i < N; i++) cin >> val[i];
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            G.push_back({val[i] ^ val[j], {i, j}});
            G.push_back({val[i] ^ val[j], {i, j}});
        }
    }
    sort(G.begin(), G.end(), greater<pair<ll, pl>>());

    ll ans = 0;

    for (auto [w, it] : G) {
        int u = fp(it.first);
        int v = fp(it.second);

        if (u != v) {
            ans += w;
            du(u, v);
        }
    }

    cout << ans;

}
