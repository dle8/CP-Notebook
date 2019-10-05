vector<int> topo_sort;

void dfs(int u) {
  visited[u] = true;
  for (int v: adj[u]) {
    if (!visited[v]) dfs(v);
  }
  topo_sort.push_back(u);
}

int main() {
  topo_sort.clear();
  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= n; ++i) if (!visited(i)) dfs(i);
  reverse(topo_sort.begin(), topo_sort.end());
  for (int i = 1; i <= n; ++i) cout << topo_sort[i] << " ";
  return 0;
}
