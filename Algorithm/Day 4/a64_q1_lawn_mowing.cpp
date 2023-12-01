#include <bits/stdc++.h>
using namespace std;

const int mxn = 5e5 + 5;
int v[mxn] = {0}, dp[mxn] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> v[i], dp[i] = dp[i - 1] + v[i];
    while (m--) {
        int a, b; cin >> a >> b;
        int l = ++a, r = n, c = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (dp[mid] - dp[a - 1] + (mid - a + 1) * k == b) { l = mid, c = 0; break; }
            if (dp[mid] - dp[a - 1] + (mid - a + 1) * k < b) l = mid + 1;
            else r = mid - 1;
        }
        cout << dp[l - c] - dp[a - 1] << '\n';
    }
}