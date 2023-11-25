#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, w, x; cin >> n >> m >> k >> w;
    vector<int> mo(m), hp(m), tw(k);
    for (auto& q : mo) cin >> q;
    for (auto& q : hp) cin >> q;
    for (auto& q : tw) cin >> q;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < m; j++)
            if (tw[i] - w <= mo[j] && mo[j] <= tw[i] + w) {
                if (hp[j] > 0) hp[j]--; break; }

    cout << accumulate(hp.begin(), hp.end(), 0LL);
}