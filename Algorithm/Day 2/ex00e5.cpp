#include <bits/stdc++.h>
using namespace std;
int n, k;
void rec(int o, int m, string s) {
    if (s.size() > n) return;
    if (m >= k && s.size() == n) cout << s << '\n';
    rec(0, m, s + '0'); rec(o + 1, max(m, o + 1), s + '1');
}
int main() {
    cin >> n >> k; rec(0, 0, "");
}