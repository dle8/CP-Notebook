/*
Author: Dung Tuan Le
University of Rochester
*/

/*
Tested: https://codeforces.com/contest/559/problem/C
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define x first
#define y second
#define sz(x) int(x.size())
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pllll;
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

const ll mod = 1000000007;
#define maxn 2000 + 10
#define maxw 100000 + 10
pllll cell[maxn];
ll fact[2 * maxw + 10], inverse[2 * maxw + 10], dp[maxn + 10];

inline ll add(ll a, ll b) {
  return (a + b + mod) % mod;
}

inline ll mul(ll a, ll b) {
  return ((a % mod) * (b % mod) + mod) % mod;
}

inline ll f(pllll a, pllll b) {
  if (b.y < a.y || b.x < a.x) return 0;
  return mul(fact[b.y - a.y + b.x - a.x], mul(inverse[b.y - a.y], inverse[b.x - a.x]));
}

inline ll POW(ll base, ll p) {
  if (p == 0) return 1;
  ll half = POW(base, p / 2);
  if (p % 2 == 0) return mul(half, half);
  return mul(mul(half, half), base);
}

int main() {
	fio;
  ll h, w, n;
  cin >> h >> w >> n;
  fact[0] = 1;
  FOR(i, 1, 2 * maxw) fact[i] = mul(fact[i - 1], i);
  inverse[2 * maxw] = POW(fact[2 * maxw], mod - 2);
  REP(i, 2 * maxw - 1, 0) inverse[i] = mul(inverse[i + 1], i + 1);
  FOR(i, 1, n) cin >> cell[i].x >> cell[i].y;
  sort(cell + 1, cell + 1 + n, [](const pllll&a, const pllll&b){
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
  });
  FOR(i, 1, n) dp[i] = f({1, 1}, cell[i]);
  FOR(i, 1, n) {
    FOR(j, 1, i - 1) {
      if (cell[i].y >= cell[j].y) dp[i] = add(dp[i], -mul(dp[j], f(cell[j], cell[i])));
    }
  }
  ll res = f({1, 1}, {h, w});
  FOR(i, 1, n) {
    res = add(res, -mul(dp[i], f(cell[i], {h, w})));
  }
  cout << res;
	return 0;
}
