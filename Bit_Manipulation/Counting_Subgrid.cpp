/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 12/6/2018
*/

/*
  Counts number of subgrird whose all corners are black.
*/

#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
using namespace std;

#define maxn 1000 + 10

char cell;
string grid[maxn];
const long n = 5;

int main() {
  FOR(i, 1, n)
  FOR(j, 1, n) {
    cin >> cell;
    grid[i] += cell;
  }

  vector<bitset<n>> bitGrid(n + 1);

  FOR(i, 1, n) {
    bitset<n> bset(string(grid[i]));
    bitGrid[i] = bset;
  }

  long tcount = 0;
  FOR(a, 1, n - 1)
  FOR(b, a + 1, n) {
    long tmp = (bitGrid[a] & bitGrid[b]).count();
    tcount += (tmp * (tmp - 1) / 2);
  }

  cout << tcount;

  return 0;
}
