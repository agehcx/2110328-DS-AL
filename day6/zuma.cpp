#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> vec(n);
    for (auto& e : vec)cin >> e;
    vec.insert(vec.begin() + m, k);
    auto lb = lower_bound(vec.begin(), vec.end(), k);
    auto ub = upper_bound(vec.begin(), vec.end(), k);
    int x = 0;
    if (ub - lb >= 2) {
        for (int i = *lb; i < *ub; i++) {
            vec.erase(vec.begin() + i + x--);
        }
    }
    for (auto& e : vec) cout << e << ' ';
}