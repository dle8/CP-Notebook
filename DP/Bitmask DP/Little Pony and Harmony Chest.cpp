/*
Author: Dung Tuan Le
University of Rochester
*/

/*
Tested: https://codeforces.com/contest/454/problem/D
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define sz(x) int(x.size())
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> Point;
typedef pair<Point, Point> line;
struct strLine { ld a, b, c; };

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

const double pi = 3.141592653589793;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

/* tach xau
string str = "Hello World", token; stringstream ss(str);
while (ss >> token) cout << token << endl;
*/

const long inf = 1e9;
#define maxn 100 + 5
long a[maxn], dp[maxn][(1 << 17) + 10], order[maxn], f[maxn], pre[maxn][(1 << 17) + 10];

bool isPrime(long x) {
  if (x <= 1) return false;
  if (x == 2 || x == 3) return true;
  FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
  return true;
}

int main() {
	fio;
  long cnt = 0;
  FOR(i, 1, 60) if (isPrime(i)) order[i] = cnt++;
  FOR(i, 1, 60) FOR(j, 2, i) if (i % j == 0 && isPrime(j)) f[i] |= (1 << order[j]);

  long n; cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) FOR(j, 0, (1 << 17) - 1) dp[i][j] = inf;
  dp[0][0] = 0;
  FOR(i, 1, n) {
    FOR(j, 1, 60) { // f[1] = 0
      if (i == 1) {
        if (dp[i][f[j]] > abs(a[i] - j)) {
          dp[i][f[j]] = abs(a[i] - j);
          pre[i][f[j]] = j;
        }
        continue;
      }
      long x = (~f[j]) & ((1 << 17) - 1);
      for (int s = x;; s = (s - 1) & x) { // iterate over all subset of x
        if (dp[i][s | f[j]] > dp[i - 1][s] + abs(a[i] - j)) {
          dp[i][s | f[j]] = min(dp[i][s | f[j]], dp[i - 1][s] + abs(a[i] - j));
          pre[i][s | f[j]] = j;
        }
        if (s == 0) break;
      }
    }
  }
  long bestIndex = 0;
  FOR(i, 0, (1 << 17) - 1) if (dp[n][bestIndex] > dp[n][i]) bestIndex = i;
  vector<long> res;
  REP(i, n, 1) {
    res.pb(pre[i][bestIndex]);
    bestIndex -= f[pre[i][bestIndex]];
  }
  REP(i, sz(res) - 1, 0) cout << res[i] << " ";
	return 0;
}
