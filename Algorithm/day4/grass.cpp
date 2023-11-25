#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxn = 5e5 + 5;
vector<ll> v(mxn, 0), dp(mxn, 0);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i]; dp[i] = dp[i - 1] + v[i];
    }
    while (m--) {
        int a, b; cin >> a >> b;
        ll l = 0, r = n;
        int c = 0;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (dp[mid] - dp[a] + (mid - a) * k == b) {
                l = mid; c = 1; break;
            }
            if (dp[mid] - dp[a] + (mid - a) * k < b) l = mid + 1;
            else r = mid - 1;
        }
        if(c) cout << dp[l] - dp[a] << '\n';
        else cout << dp[l - 1] - dp[a] << '\n';
    }
}