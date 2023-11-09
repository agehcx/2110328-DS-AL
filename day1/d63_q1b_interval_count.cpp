#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    vector<int> q(m);
    for (auto& e : v) cin >> e;
    for (auto& e : q) cin >> e;
    sort(v.begin(), v.end());
    for (auto& e : q) {
        cout << upper_bound(v.begin(), v.end(), e + k) - lower_bound(v.begin(), v.end(), e - k) << ' ';
    }
}