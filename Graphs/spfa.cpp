/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 08/20/2020
*/

/*
  Shortest Path Faster Algorithm (SPFA) - improvement of the Bellman–Ford algorithm, which computes single-source
  shortest paths in a weighted directed graph. Work well on random sparse graphs and is for graphs that contain
  negative-weight edges.[1]

  The worst-case complexity of SPFA is the same as that of Bellman–Ford, so for graphs with nonnegative edge weights
  Dijkstra's algorithm is preferred.
*/

#define oo 1e9

long min(long a, long b) { return (a <= b) ? a : b; }

struct edge {
    long u, v, c;//a edge from vertice u to vertice v with weight c
}

vector<edge> edges;

// return a shortest path from s to t, if not exist then return -1
long SPFA(long s) {
    // d[i]: min distance from s to i
    FOR(i, 1, n) d[i] = oo;
    d[s] = 0;

    // Relax all E edges V - 1 times.
    // If E edges are relaxed V - 1 times, the shortest path from the source vertex to furthest vertex from the source
    // (which will be a simple path with V - 1 edges) should have been correctly computed.
    queue<long> q;
    q.push(s);
    unordered_map<int, bool> in_queue;
    while (!q.empty()) {
        long u = q.front();
        q.pop();
        for (auto edge: edges) {
            long u, v, c;
            tie(u, v, c) = edge;
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                if (!in_queue[v]) {
                    in_queue[v] = true;
                    q.push(v);
                }
            }
        }
    }

}

/*
    Optimizations - change d from queue to deque:
    - Small Label First: instead of always pushing vertex v to the end of the queue, we compare d[v] and d[q.front()]
    and insert v into the front of the queue if d[v] is smaller.
        if d[v] < d[q.front()] {
            q.push_front(v);
        } else q.push_back(v);

    - Large Label Last:  update the queue so that the first element is smaller than the average, and any element larger
    than the average is moved to the end of the queue
    double x = average of d[v], for all v in q
        while (d.front() > x) {
            u = d.front();
            d.pop_front();
            d.push_back(u);
        }
 * */
