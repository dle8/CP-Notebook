/*
Author: Dung Tuan Le
University of Rochester
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

ll getBit(ll bit, ll x) {
 return (1 & (x >> bit));
}

#define maxn 20
ll a[maxn];

int main() {
	fio;
  ll test_cases, n, p;
  cin >> test_cases;
  FOR(current_test, 1, test_cases) {
    cin >> n >> p;
    set<ll> mset;
    FOR(i, 0, p - 1) {
      cin >> a[i];
      mset.insert(a[i]);
    }
    p = sz(mset);
    long tmp = -1;
    for (auto iter = mset.begin(); iter != mset.end(); iter++) {
      a[++tmp] = *iter;
    }
    ll res = 0;
    FOR(subset, 1, (1 << p) - 1) {
      ll tmp = 1;
      FOR(bit, 0, p - 1) if (getBit(bit, subset) == 1) {
        if ((tmp - n / ld(a[bit])) > eps) {
          tmp = 0;
          break;
        }
        else tmp *= a[bit];
      }
      if (tmp == 0) continue;
      if (__builtin_popcount(subset) % 2 == 0) res -= ll(n / tmp);
      else res += ll(n / tmp);
    }
    cout << res << '\n';
  }

	return 0;
}
