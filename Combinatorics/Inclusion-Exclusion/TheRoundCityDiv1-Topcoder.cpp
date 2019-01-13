/*
Author: Dung Tuan Le
University of Rochester
*/

/*
	Tested: https://community.topcoder.com/stat?c=problem_statement&pm=14897
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define pb push_back
#define sz(x) x.size()

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

inline ll min(ll a, ll b) { return (a <= b) ? a : b; }
inline ll max(ll a, ll b) { return (a >= b) ? a : b; }
#define maxn 1500000
vector<vector<ll>> eras(maxn);
class TheRoundCityDiv1 {
	public:

	void selectPrimes() {
		eras[1] = {-1}; eras[0] = {-1};
		ll num = 2;
		while (num < 1000000) {
			if (sz(eras[num]) == 0) {
				ll tmp = num;
				while (tmp < 1000000) {
					eras[tmp].pb(num);
					tmp += num;
				}
			}
			num++;
		}
	}

  ll getBit(ll index, ll x) {
    return (1 & (x >> index));
  }

	ll find(ll r) {
		selectPrimes();
    ll res = 0;
    FOR(x, 0, r) {
      if (x == 0) res += 2; // (0, 1), (0, -1)
      else if (x == r) res += 2; // (1, 0), (-1, 0)
      else if (x == 1 && r != 1) res += 4; // (1, 1), (1, -1), (-1, -1), (-1, 1)
      else {
        ll y = sqrt(1LL * r * r - 1LL * x * x);
        res += process(x, min(x, y));
      }
    }
    return res;
	}

  ll process(ll x, ll bound) {
    // inclusion - exclusion
		vector<ll> primeFactors = eras[x];
		if (sz(primeFactors) > 0 && primeFactors[0] == -1) return 0;
    ll res = 0;
    FOR(subset, 1, (1 << sz(primeFactors)) - 1) {
      ll tmp = 1;
      FOR(index, 0, sz(primeFactors) - 1){
        if (getBit(index, subset) == 1LL) tmp *= primeFactors[index];
      }
      if (__builtin_popcount(subset) % 2 != 0) res += ll(bound / tmp);
      else res -= ll(bound / tmp);
    }
    // res bh la nhung thang chia het cho 1 trong cac uoc ngto cua x ma <= x
    res = 4 * 2 * max(0, bound - res);
    return res;
  }
};

int main() {
	fio;

  // freopen("input.txt", "r", stdin);
  // FOR(current_test, 1, 20) {
    ll r;
    cin >> r;
    TheRoundCityDiv1 city;
    // cout << "Test #" << current_test << ": " << city.find(r) << '\n';
    cout << city.find(r) << '\n';
  // }
  // fclose(stdin);

	return 0;
}
