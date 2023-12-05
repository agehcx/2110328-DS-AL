#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6 + 3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    int dp[N + 2] = {0};
    int mem[Q];
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        dp[x] = 1;
        mem[i] = x;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < Q; j++) {
            if(i > mem[j]) dp[i] += dp[i - mem[j]] % MOD;
            dp[i] = dp[i] % MOD;
        }
    }
    cout << dp[N];
}