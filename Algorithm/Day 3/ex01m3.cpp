#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, a; cin >> n >> a;
    vector<ll> v(n);
    for (auto& e : v) cin >> e;
    for (;a--;) {
        ll res, x, l = 0, r = 1e12;
        cin >> x;
        while (l < r) {
            ll m = l + (r - l) / 2, s = 0;
            for (auto& e : v) s += (m/e + 1);
            if (s >= x) {
                res = m;
                r = m;
            } else l = m + 1;
        }
        cout << res << '\n';
    }
}