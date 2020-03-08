#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll maxn = 1e6 + 10;
vector<ll> mobius(maxn), lp(maxn, 0);
vector<ll> primes;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    mobius[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] < maxn; ++j) {
            if (lp[i * primes[j]] == 0) lp[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
        mobius[i] = [](int x) {
            int cnt = 0; // number of prime factor
            while (x > 1) {
                int k = 0, d = lp[x];
                while (x % d == 0) {
                    x /= d;
                    ++k;
                    if (k > 1) return 0;
                }
                ++cnt;
            }
            if (cnt & 1) return -1;
            return 1;
        }(i);
    }
    ll test;
    cin >> test;
    for (ll cur_test = 1; cur_test <= test; ++cur_test) {
        ll m, n; cin >> m >> n;
        if (m == 0 || n == 0) {
            cout << "Case " << cur_test << ": " << 1 << '\n';
            continue;
        }
 
        if (m > n) swap(m, n);
        ll res = 2;
        for (ll d = 1; d <= m; ++d) {
//            cout << d << " " << mobius[d] << '\n';
            res += mobius[d] * (ll)(m / d) * (ll)(n / d);
        }
        cout << "Case " << cur_test << ": " << res << '\n';
    }
    return 0;
}
