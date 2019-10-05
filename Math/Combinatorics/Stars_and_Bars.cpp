/*
Author: Dung Tuan Le
University of Rochester
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
  ll m, k;
  fact[0] = 1;
  FOR(i, 1, maxn) fact[i] = (fact[i - 1] * i) % mod;
  inverse[maxn] = POW(fact[maxn], mod - 2);
  REP(i, maxn - 1, 0) inverse[i] = (inverse[i + 1] * (i + 1)) % mod;
  cin >> m >> k;
  // (# of solution for sum of m numbers equals to k) % mod
  // positive solution
  cout << mul(fact[k - 1], mul(inverse[k - m], inverse[m - 1]));
  // non-negative solution
  cout << mul(fact[k + m - 1], mul(inverse[k], inverse[m - 1]));
	return 0;
}
