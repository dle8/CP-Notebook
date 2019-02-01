/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define pb push_back
#define sz(x) int(x.size())

using namespace std;

#define maxn 500 + 10
bool check[maxn], foundCycle;
vector<long> neighbor[maxn];
long parent[maxn], tend, start;

void dfs(long u) {
  check[u] = true;
  FOR(i, 0, sz(neighbor[u]) - 1) {
    if (foundCycle) return;
    long v = neighbor[u][i];
    if (!check[v] && parent[v] == 0) {
      parent[v] = u;
      dfs(v);
      if (foundCycle) return;
    }
    else if (check[v]) {
      foundCycle = true;
      tend = u;
      start = v;
    }
    if (foundCycle) return;
  }
  check[u] = false;
}

int main() {
	fio;
  long n, m; cin >> n >> m;
  FOR(i, 1, m) {
    long u, v; cin >> u >> v;
    neighbor[u].pb(v);
  }
  foundCycle = false;
  memset(check, false, sizeof(check));
  FOR(i, 1, n) if (parent[i] == 0) {
    parent[i] = -1;
    dfs(i);
  }
  if (!foundCycle) return cout << "No cycle found.", 0;
  cout << "Found a cycle: " << '\n';
  vector<long> path;
  while (tend != start) {
    path.pb(tend);
    tend = parent[tend];
  }
  path.pb(start);
  path.pb(path[0]);
  REP(i, sz(path) - 1, 1) cout << path[i] << " " << path[i - 1] << '\n';
	return 0;
}
