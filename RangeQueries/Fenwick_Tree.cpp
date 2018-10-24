/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 08/17/2018
*/

/*
  A binary indexed tree (or Fenwick Tree) provides two operations with complexity of O(logN):
  - Processing range sum.
  - Update a value.

  Fenwick Tree shares some common features with Segment Tree, in which both can process range queries,
  and update a value. However, Fenwick Tree, in many cases, runs faster than Segment Tree. This is due to the
  property of information contained by each node in Fenwick Tree. Also, Fenwick Tree has better space complexity
  than Segment Tree(O(n) compared to O(4 * n))
*/

/*
  Below is the example of Segment Tree that returns sum of elements in a range [l, r] of an array.
*/

/*
 Tested: https://vn.spoj.com/problems/FOCUS/
*/

// memory complexity O(n)
long ft[maxn];

void update(long i, long val) {
  for(; i <= n; i += (i & (-i))) ft[i] += val;
}

// This take the sum of elements indexed from [1, i]
long sum(long i) {
  long sum = 0;
  for (; i > 0; i -= (i & (-i))) sum += ft[i];
  return sum;
}

// Sum of elements indexed from [l, r] = Sum of elements indexed from [1, r] - Sum of elements indexed from [1, l - 1]
long sum(long l, long r) {
  return (sum(r) - sum(l - 1));
}

// FOR(i, 1, n) update(i, a[i]);
// cout << sum(l, r);
