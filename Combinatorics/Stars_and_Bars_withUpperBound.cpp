/*
Author: Dung Tuan Le
University of Rochester
*/

/*
Tested: http://acm.hdu.edu.cn/showproblem.php?pid=6397
*/

#include <iostream>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
using namespace std;

typedef long long ll;
const ll mod = 998244353;
#define maxn 200000 + 10
ll fact[maxn + 10], inverse[maxn + 10];

inline ll add(ll x, ll y) {
  return (x + y + mod) % mod;
}

inline ll mul(ll x, ll y) {
  return (x * y) % mod;
}

ll POW(ll x, ll y) {
  if (y == 0) return 1;
  ll half = POW(x, y / 2);
  if (y % 2 == 0) return mul(half, half);
  return mul(mul(half, half), x);
}

int main() {
	fio;
  fact[0] = 1;
  inverse[0] = 1;
  FOR(i, 1, maxn) fact[i] = (fact[i - 1] * i) % mod;
  inverse[maxn] = POW(fact[maxn], mod - 2);
  REP(i, maxn - 1, 0) inverse[i] = (inverse[i + 1] * (i + 1)) % mod;
  ll test_cases, n, m, k;
  cin >> test_cases;
  FOR(current_test, 1, test_cases) {
    cin >> n >> m >> k;
    ll res = 0;
    FOR(i, 0, m) {
      if (n * i > k) break;
      ll sign = ((i % 2 == 0) ? 1 : -1);
      ll chooseGreater = mul(fact[m], mul(inverse[i], inverse[m - i]));
      ll cnt = mul(fact[k - 1LL * n * i + m - 1], mul(inverse[m - 1], inverse[k - 1LL * n * i]));
      res = add(res, 1LL * sign * mul(chooseGreater, cnt));
    }
    res = (res + mod) % mod;
    cout << res << '\n';
  }
	return 0;
}
