#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n), s;
    for (auto& e : v) cin >> e;
    int lw = 0, gt = 0;
    s = v;
    sort(s.begin(), s.end());
    for (int i = 0; i < n;i++) {
        if (v[i] < s[i]) lw++;
        if (v[i] > s[i]) gt++;
    }
    cout << max(lw, gt);
}