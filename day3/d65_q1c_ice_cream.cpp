#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

const int mxn = 1e5 + 5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, st;
    std::cin >> n >> m >> st;
    std::unordered_map<int, int> mp;
    std::vector<int> v(mxn, 0);
    for (;n--;) {
        int a, b; std::cin >> a >> b;
        mp[a] = b;
    }
    int prev = st;
    v[0] = st;
    for (int i = 1; i < mxn; i++) {
        if (mp[i]) {
            v[i] = v[i - 1] + mp[i];
            prev = mp[i];
        } else {
            v[i] = v[i - 1] + prev;
        }
    }
    for (;m--;) {
        int a, b; std::cin >> a >> b;
        if (v[b] >= a) {
            std::cout << std::lower_bound(v.begin(), v.begin() + b + 1, a) - v.begin() << ' ';
        } else {
            std::cout << std::lower_bound(v.begin() + b, v.end(), a + v[b]) - v.begin() << ' ';
        }
    }

}