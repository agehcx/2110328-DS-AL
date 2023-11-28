#include <iostream>
const int M = 1e8 + 7;

int main() {
    int f = 1, s = 3, t = 7, r, n; std::cin >> n;
    if (n == 1) std::cout << f;
    else if (n == 2) std::cout << s;
    else {
        for (int i = 2; i < n; i++) {
            r = ((3 * t) % M - s + M - f + M) % M;
            f = s, s = t, t = r;
        }
        std::cout << r;
    }
}