/*
  Author: Dung Tuan Le
  Universsty of Rochester
  Created: 08/15/2018
*/

/*
  A Segment Tree is data structure that provides 2 operations (both run in O(logn) time complexsty):
  - Process a range query: eg. find the number that contains a specific special features in a range(min, max in value)
                                  or sum of all elements' value in the given range.
  - Update an array value: (have to update for at most O(logn) other nodes in the tree)
*/

/*
  Below is the example of Segment Tree that returns a minimum value in a given range
*/
#define oo 1e9
#define maxn 1000+10
long st[3 * maxn];

// ind is the index of the node in the Segment Tree

long min(long a, long b) { return (a <= b) ? a : b; }

// init all values of st = oo;

// update whole values of array a indexed from l to r into Segment Tree
void update(long ind, long l, long r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  long mid = (l + r)/2;
  update(2 * id, l, mid);
  update(2 * id + 1, mid + 1, r);
  st[id] = min(st[2 * id], st[2 * id + 1]);
}

// update a[i] whose value is val into Segment Tree
void update(long ind, long l, long r, long i, long val) {
  if (i < l || r < i) return;
  st[cs] = min(st[cs], val);
  if (l == r) return;
  long mid = (l + r)/2;
  update(2 * ind, l, mid, i, val);
  update(2 * ind + 1, mid + 1, r, i, val);
}

// return the minimum value in range [u, v]
long minST(long ind, long l, long r, long u, long v) {
  if (v < l || r < u) return oo;
  if (u <= l && r <= v) return st[ind];
  long mid = (l + r)/2;
  return min(minST(2 * ind, l, mid, u, v), minST(2 * ind + 1, mid + 1, r, u, v));
}
