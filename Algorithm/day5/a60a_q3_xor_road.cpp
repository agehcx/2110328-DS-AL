#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> pl;

const int MXN = 2e3 + 7;
vector<vector<pl>> v(MXN);
int p[MXN];

int fp(int u) {
    if (u == p[u]) return u;
    return p[u] = fp(p[u]);
}

bool dju(int u, int v) {
    u = fp(u);
    v = fp(u);
    if (u == v) return false;
    p[v] = u; return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    ll val[N];
    for (int i = 0; i < N; i++) cin >> val[i];
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            v[i].push_back({val[i] ^ val[j], j});
            v[j].push_back({val[i] ^ val[j], i});
        }
    }
    
    
}
