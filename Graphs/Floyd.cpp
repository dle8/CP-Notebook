/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 06/06/2018
*/

/*
  Floyd-Warshall Algorithms: find the shortest distance between every pair of vertices in a given graph
  Time complexity: O(n^3)
*/
#define oo 1e9
#define maxn 1000 + 10

long d[maxn][maxn]; //d[u][v] is the shortest distance betweeen vertice u & vertice v

//init all d[u][v] = oo when u != v, else d[u][v] = 0

void floyd() {
  FOR(k, 1, n)
  FOR(u, 1, n)
  FOR(v, 1, n) {
    if (d[u][v] > d[u][k] + d[k][v]) {
      d[u][v] = d[u][k] + d[k][v];
      trace[u][v] = trace[u][k];
    }
  }
}
