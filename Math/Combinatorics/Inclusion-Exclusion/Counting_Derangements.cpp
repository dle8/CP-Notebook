// Task: https://www.spoj.com/problems/ADADUNG/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll maxn = 1e7 + 10;

ll fact[maxn], inv[maxn], a[maxn];

inline ll mul(ll x, ll y) {
    return ((x * y) % mod + mod) % mod;
}

inline ll POW(ll x, ll y) {
    if (y == 0) return 1;
    ll half = POW(x, y / 2);
    if (y % 2 == 0) return mul(half, half);
    return mul(mul(half, half), x);
}

inline ll c(ll k, ll n) {
    return (fact[n] * inv[k] * inv[n - k]) % mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    ll test_cases; cin >> test_cases;
    ll max_bound = 0;
    for (ll cur_test = 1; cur_test <= test_cases; ++cur_test) {
        cin >> a[cur_test];
        max_bound = max(max_bound, a[cur_test]);
    }
    fact[0] = 1;
    for (int i = 1; i <= max_bound; ++i) fact[i] = (fact[i - 1] * i) % mod;
    inv[max_bound] = POW(fact[max_bound], mod - 2);
    for(int i = max_bound - 1; i >= 0; --i) inv[i] = (inv[i + 1] * (i + 1)) % mod;
    for (ll cur_test = 1; cur_test <= test_cases; ++cur_test) {
        ll n = a[cur_test];
        ll res = 0, sign = 1;
        for (ll i = 1; i <= n; ++i) {
            res += (c(i, n) * fact[n - i] * sign) % mod;
            sign = -sign;
        }
        res %= mod;
        cout << ((fact[n] - res) % mod + mod) % mod << '\n';
    }
    return 0;
}