/*
    Author: Dung Tuan Le
    University of Rochester
    Created: 08/20/2020
*/

#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    }
};

const int inf = 1e9 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    // start at 1
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({1, 0});
    vector<bool> taken(n + 1, false);
    vector<int> d(n + 1, inf);
    int tree_node = 0, w = 0;
    while (!pq.empty()) {
        pair<int, int> u = pq.top();
        pq.pop();
        if (taken[u.first]) continue;
        taken[u.first] = true;
        w += u.second;
        ++tree_node;
        if (tree_node == n) break;
        for (pair<int, int> v: adj[u.first]) {
            if (!taken[v.first]) {
                pq.push({v.first, v.second});
            }
        }
    }
    cout << w;
    return 0;
}