#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;
vector<int> s(21,0);
vector<bool> used(21,false);
int n, k;

void rec(int k) {
    if (k == n) {
        for (auto c : s) cout << c << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i] && (mp.find(i) == mp.end() || used[mp[i]])) {
            s[k] = i;
            used[i] = true;
            rec(k + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    used.resize(n);
    s.resize(n);
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        mp[b] = a;
    }
    rec(0);
}