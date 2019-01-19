/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define x first
#define y second
#define sz(x) int(x.size())

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pllll;

const ll mod = 1000000007;
#define maxn 100000 + 10
#define maxk 2000 + 10
ll fact[2 * maxn + 10], inverse[2 * maxn + 10], dp[maxk][maxk], cnt[maxk], to[maxk], dist1[maxk], dist2[maxk], dist[maxk][maxk];
pllll ano[maxk];

inline ll add(ll a, ll b) {
  return ((a + b) % mod + mod) % mod;
}

inline ll mul(ll a, ll b) {
  return ((a % mod) * (b % mod) + mod) % mod;
}

inline ll f(const pllll&a, const pllll&b) {
  if (b.x < a.x || b.y < a.y) return 0;
  return mul(fact[b.x - a.x + b.y - a.y], mul(inverse[b.x - a.x], inverse[b.y - a.y]));
}

inline ll POW(ll base, ll p) {
  if (p == 0) return 1;
  ll half = POW(base, p / 2);
  if (p % 2 == 0) return mul(half, half);
  return mul(mul(half, half), base);
}

int main() {
	fio;
  fact[0] = 1;
  FOR(i, 1, 2 * maxn) fact[i] = mul(fact[i - 1], i);
  inverse[2 * maxn] = POW(fact[2 * maxn], mod - 2);
  REP(i, 2 * maxn - 1, 0) inverse[i] = mul(inverse[i + 1], i + 1);
  ll n, m, k, s;
  cin >> n >> m >> k >> s;
  FOR(i, 1, k) cin >> ano[i].x >> ano[i].y;
  sort(ano + 1, ano + 1 + k, [](const pllll&a, const pllll&b){
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
  });
  FOR(i, 1, k) {
    dist1[i] = f({1, 1}, ano[i]);
    dist2[i] = f(ano[i], {n, m});
    FOR(j, i + 1, k) dist[i][j] = f(ano[i], ano[j]);
  }
  REP(i, k, 1) {
    cnt[i] = dist2[i];
    FOR(j, i + 1, k) cnt[i] = add(cnt[i], -mul(cnt[j], dist[i][j]));
    dp[i][0] = cnt[i];
  }
  REP(i, k, 1) {
    ll pre = dp[i][0];
    FOR(v, 1, 19) {
      dp[i][v] = dist2[i];
      FOR(j, i + 1, k) dp[i][v] = add(dp[i][v], -mul(dist[i][j], dp[j][v]));
      dp[i][v] = add(dp[i][v], -pre);
      pre = add(pre, dp[i][v]);
    }
  }
  ll total = f({1, 1}, {n, m});
  FOR(i, 1, k) {
    to[i] = dist1[i]; // to[i]: number of paths that start whom the first anomaly it meets is anomaly[i]
    FOR(j, 1, i - 1) to[i] = add(to[i], -mul(to[j], dist[j][i]));
    total = add(total, -mul(to[i], dist2[i]));
  }
  ll res = 0;
  res = add(res, mul(s, total));
  total = add(f({1, 1}, {n, m}), -total);
  FOR(i, 1, 20) {
    if (s == 1) break;
    s -= (s / 2);
    ll sum = 0;
    FOR(j, 1, k) {
      sum = add(sum, mul(to[j], dp[j][i - 1]));
      total = add(total, -mul(to[j], dp[j][i - 1]));
    }
    res = add(res, mul(s, sum));
  }
  res = add(res, total);
  res = mul(res, mul(fact[n - 1], fact[m - 1]));
  res = mul(res, inverse[n - 1 + m - 1]);
  cout << res;
	return 0;
}
