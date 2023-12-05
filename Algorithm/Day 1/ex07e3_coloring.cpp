#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, e; cin >> n >> e;
    unordered_map<int, int> mp;
    unordered_map<int, vector<int>> color;
    int ans = 1;
    while (e--) {
        int x, y; cin >> x >> y;
        mp[x] = 1; mp[y] = 1;
        color[x].push_back(y);
        color[y].push_back(x);
    }
    for (auto& a : color) {
        cout << a.first << "\n=> ";
        for (auto& b : a.second) {
            cout << b << ' ';
            if (mp[a.first] == mp[b]) {
                mp[b]++;
            }
        }
        cout << '\n';
    }
    for (auto& c : mp) ans = max(ans, c.second);
    int tmp = ans;
    for (auto& a : color) {
        for (auto& b : a.second) {
            if (mp[a.first] == mp[b]) {
                mp[b]++;
            }
        }
    }
    for (auto& c : mp) ans = max(ans, c.second);
    if (tmp == ans - 1) tmp--;
    cout << tmp;
}


int main() 
    int n; cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for (int sz = 2; sz <= n; sz++) {
        for (int i = 1;i + sz - 1 <= n;i++) {
            int j = i + sz - 1;
            dp[i][j] = max(dp[i][j - 1] + a[j], dp[i + 1][j] + a[i]) + abs(a[i] - a[j]);
        }
    }
    for (int i = 2;i <= n;i++) {
        for (int j = 1;j < i;j++) {
            dp[1][i] = max(dp[1][i], dp[1][j] + dp[j + 1][i]);
        }
    }
    cout << dp[1][n];
}