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

ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

/* tach xau
string str = "Hello World", token; stringstream ss(str);
while (ss >> token) cout << token << endl;
*/

#define maxn 100000 + 10
vector<long> neighbor[maxn], rneighbor[maxn], cc[maxn];
bool check[maxn], cycle[maxn], inGraph[maxn];
long wcc, x[maxn], y[maxn], cnt, number[maxn], low[maxn];
stack<long> Stack;

void dfs(long u) {
  check[u] = true;
  cc[wcc].pb(u);
  FOR(i, 0, sz(neighbor[u]) - 1) {
    long v = neighbor[u][i];
    if (!check[v]) dfs(v);
  }
}

void dfs2(long u) {
  cnt++;
  number[u] = cnt;
  low[u] = number[u];
  Stack.push(u);
  FOR(i, 0, sz(neighbor[u]) - 1) {
    long v = neighbor[u][i];
    if (inGraph[v]) {
      if (number[v] != 0) low[u] = min(low[u], number[v]);
      else {
        dfs2(v);
        low[u] = min(low[u], low[v]);
      }
    }
  }
  if (low[u] == number[u]) {
    long v;
    vector<long> tmp;
    do {
      if (Stack.empty()) break;
      v = Stack.top();
      Stack.pop();
      inGraph[v] = false;
      tmp.pb(v);
    } while (v != u);
    if (sz(tmp) > 1) cycle[tmp[0]] = true;
  }
}

int main() {
	fio;
  long n, m;
  cin >> n >> m;
  FOR(i, 1, m) {
    cin >> x[i] >> y[i];
    neighbor[x[i]].pb(y[i]);
    neighbor[y[i]].pb(x[i]);
  }
  wcc = 0;
  memset(check, false, sizeof(check));
  FOR(i, 1, n) if (!check[i]) {
    ++wcc;
    dfs(i);
  }
  FOR(i, 1, n) neighbor[i].clear();
  FOR(i, 1, m) neighbor[x[i]].pb(y[i]);
  memset(check, false, sizeof(check));
  memset(cycle, false, sizeof(cycle));
  cnt = 0;
  memset(inGraph, true, sizeof(inGraph));
  FOR(i, 1, n) if (!check[i]) dfs2(i);
  long res = 0;
  FOR(i, 1, wcc) {
    bool hasCycle = false;
    FOR(j, 0, sz(cc[i]) - 1) if (cycle[cc[i][j]]) hasCycle = true;
    // cout << hasCycle << '\n';
    res += (sz(cc[i]) - (hasCycle == false));
  }
  cout << res;
	return 0;
}
