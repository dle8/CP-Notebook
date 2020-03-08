#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e7 + 10;
vector<ll> mobius(maxn), lp(maxn, 0);
vector<ll> primes;

int main() {
    mobius[1] = 1;
    // Linear sieve and Mobius Inversion
    for (ll i = 2; i < maxn; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (ll j = 0; j < primes.size() && i * primes[j] < maxn; ++j) {
            if (lp[i * primes[j]] == 0) lp[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
        mobius[i] = [](ll x) {
            ll cnt = 0; // number of prime factor
            while (x > 1) {
                ll k = 0, d = lp[x];
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
    return 0;
}
