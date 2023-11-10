#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<std::pair<int, int>> v(n);
    for (auto& [yy, mm] : v) std::cin >> yy >> mm;
    sort(v.begin(), v.end());
    for (;m--;) {
        int a, b; std::cin >> a >> b;
        auto it = lower_bound(v.begin(), v.end(), std::make_pair(a, b));
        if (*it == std::pair(a, b)) std::cout << "0 0 ";
        else if (it == v.begin()) std::cout << "-1 -1 ";
        else {
            auto [x, y] = *(--it);
            std::cout << x << ' ' << y << ' ';
        }
    }
}