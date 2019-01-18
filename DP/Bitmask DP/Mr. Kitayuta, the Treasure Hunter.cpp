/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
// #define _TIME
#define sz(x) int(x.size())

using namespace std;

typedef long long ll;
ll max(ll a, ll b) { return (a>=b)?a:b; }

#define maxn 30000 + 10
ll dp[maxn][250 * 2], n, d, gem[maxn];
bool used[maxn][250 * 2];

ll solve(ll i, ll j) {
  ll jj = j - (d - 246);
  if (i > 30000) return 0;
  if (used[i][jj]) return dp[i][jj];
  used[i][jj] = true;
  ll res = 0;
  if (j == 1) res = gem[i] + max(solve(i + j, j), solve(i + j + 1, j + 1));
  else res = gem[i] + max(max(solve(i + j - 1, j - 1), solve(i + j, j)), solve(i + j + 1, j + 1));
  dp[i][jj] = res;
  return dp[i][jj];
}

int main() {
#ifdef _TIME
  //freopen("", "r", stdin);
  long tt = clock();
#endif

	fio;
  cin >> n >> d;
  FOR(i, 1, n) {
    ll p;
    cin >> p;
    gem[p]++;
  }
  cout << solve(d, d);

#ifdef _TIME
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif

	return 0;
}
