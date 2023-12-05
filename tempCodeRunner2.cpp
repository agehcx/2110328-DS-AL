#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binpow(ll a, ll b, ll c) {
    ll res = 1;

    while (b > 0) {
        if (b & 1) {
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b = b / 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a = 2, b = 87, c = 100;

    cout << binpow(a, b, c);
}