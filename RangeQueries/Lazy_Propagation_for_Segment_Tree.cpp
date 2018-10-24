/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 08/20/2018
*/

/*
  Demonstration of Lazy Propagation for Segment Tree that returns the maximum value in a given range [l, r]
  Lazy Propagation allows faster update than normal Segment Tree, because the update stops at the
  ancestor nodes whose ranges completely contains [l, r] instead of continuing going down into other nodes below.
*/

#define maxn 1000 + 10
#define oo 1e9

long max(long a, long b) { return (a >= b) ? a : b; }

long st[4 * maxn], lazy[4 * maxn];

void update(long index, long u, long v, long l, long r, long val) {
  if (r < u || v < l) return;
  if (l <= u && v <= r) {
    lazy[index] += val;
    return;
  }
  long mid = (u + v)/2;
  update(2 * index, u, mid, l, r, val);
  update(2 * index + 1, mid + 1, v, l, r, val);
  st[index] = max(st[2 * index] + lazy[2 * index], st[2 * index + 1] + lazy[2 * index + 1]);
}

long maxST(long index, long u, long v, long l, long r) {
  if (r < u || v < l) return -oo;
  if (l <= u && v <= r) return st[index] + lazy[index];
  long mid = (u + v)/2;
  return max(maxST(2 * index, u, mid, l, r), maxST(2 * index + 1, mid + 1, v, l, r)) + lazy[index];
}
