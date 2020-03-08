#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e7 + 10;
vector<ll> mobius(maxn), lp(maxn, 0);
vector<ll> primes;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    mobius[1] = 1;
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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll bound = min(b, d), res = 0;
    for (ll gcd = 1; gcd <= bound; ++gcd) {
        ll ca = a, cc = c;
        if (ca % gcd != 0) ca += (gcd - ca % gcd);
        if (cc % gcd != 0) cc += (gcd - cc % gcd);
        if (ca <= b) ca = (b - ca) / gcd + 1; else ca = 0;
        if (cc <= d) cc = (d - cc) / gcd + 1; else cc = 0;
        res += mobius[gcd] * ca * cc;
    }
    cout << res;
    return 0;
}

