#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
using namespace std;

#define maxn 1000 + 10

struct node {
  long v;
  node* next;
};

node* head[maxn];
long parent[maxn], after1[maxn], after2[maxn], down1[maxn], down2[maxn], maxLength1[maxn], maxLength2[maxn], l1[maxn], l2[maxn];

void dfs(long u) {
  node* p = head[u];
  while (p != nullptr) {
    long v = p->v;
    if (parent[v] == 0) {
      parent[v] = u;
      dfs(v);
      if (down1[u] < down1[v] + 1) {
        down1[u] = down1[v] + 1;
        after1[u] = v; // after1[i] is the next node in the longest path from i to a leaf
      }
    }
    p = p->next;
  }

  p = head[u];
  while (p != nullptr) {
    long v = p->v;
    if (parent[v] == u) {
      if (down2[u] < down1[v] + 1 && after1[u] != v) {
        down2[u] = down1[v] + 1;
        after2[u] = v;
      }
    }
    p = p->next;
  }
}

void update(long u) {
  node* p = head[u];
  while (p != nullptr) {
    long v = p->v;
    if (parent[v] == u) {
      maxLength1[v] = down1[v];
      l1[v] = after1[v];
      if (after1[u] == v) {
        if (maxLength1[v] < maxLength2[u] + 1) {
          maxLength1[v] = maxLength2[u] + 1;
          l1[v] = u;
        }
      }
      else {
        if (maxLength1[v] < maxLength1[u] + 1) {
          maxLength1[v] = maxLength1[u] + 1;
          l1[v] = u;
        }
      }
    }
    p = p->next;
  }

  p = head[u];
  while (p != nullptr) {
    long v = p->v;
    if (parent[v] == u) {
      if (l1[v] == after1[v]) {
        maxLength2[v] = down2[v];
        l2[v] = after2[v];
        if (after1[u] == v) {
          if (maxLength2[v] < maxLength2[u] + 1) {
            maxLength2[v] = maxLength2[u] + 1;
            l2[v] = u;
          }
        }
        else {
          if (maxLength2[v] < maxLength1[u] + 1) {
            maxLength2[v] = maxLength1[u] + 1;
            l2[v] = u;
          }
        }
      }
      else if (l1[v] == u) {
        maxLength1[v] = down1[v];
        l1[v] = after1[v];
      }
    }
    p = p->next;
  }
}

int main() {
  long n, u, v;
  cin >> n;
  node* p;
  FOR(i, 1, n - 1) {
    cin >> u >> v;
    p = new node;
    p->v = v;
    p->next = head[u];
    head[u] = p;

    p = new node;
    p->v = u;
    p->next = head[v];
    head[v] = p;
  }

  parent[1] = -1;
  dfs(1);

  maxLength1[1] = down1[1];
  maxLength2[1] = down2[1];
  update(1);
  cout << "---------" << '\n';
  FOR(u, 1, n) cout << u << " " << maxLength1[u] << '\n';
  return 0;
}
