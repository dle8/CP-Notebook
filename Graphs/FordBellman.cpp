/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 08/27/2018
*/

/*
  Ford-Bellman algorithm: find the shortest path between 2 vertices (u, v) in a graph that
  contains negative-valued edges, but does not contains negative circuit
*/

#define oo 1e9

long min(long a, long b) { return (a <= b) ? a : b; }

struct edge {
  long u, v, c;//a edge from vertice u to vertice v with weight c
}

vector<edge> edges;

// return a shortest path from s to t, if not exist then return -1
long FordBellman(long s, long t) {
  FOR(i, 1, n) d[i] = oo;
  d[s] = 0;

  // Relax all E edges V - 1 times.
  // If E edges are relaxed V - 1 times, the shortest path from the source vertex to furthest vertex from the source
  // (which will be a simple path with V - 1 edges) should have been correctly computed.
  FOR(i, 1, n - 1) {
    for (auto edge: edges) {
        long u, v, c;
        tie(u, v, c) = edge;
        d[v] = min(d[v], d[u] + c);
    }
  }

  return ((d[t] == oo) ? -1 : d[t])
}
