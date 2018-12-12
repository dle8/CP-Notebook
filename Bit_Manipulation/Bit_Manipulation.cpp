/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 10/22/2018
*/

/*
Bit manipulation
*/

/*
  Not operation(~) produces a number where all the bits of x have been inverted
  ~x = -x - 1.
*/

/*
  Bit shift:
  Left bit shift appends k zero bits to the number, and right bit shift removes the k last bits from the number.
  In other words, (x << k) is multiplying x by pow(2, k), and (x >> k) is dividing x by pow(2, k)
*/

// get the i-th bit of number x, i starts from 0. if i starts from 1, change i to i - 1
long getBit(long i, long x) {
  return (1 & (x >> i));
}

// set the i-th bit to value of number x, i starts from 0. if i starts from 1, change i to i - 1
long setBit(long i, long x, long value) {
  if (value == 1) x |= (1 << i);
  else x &= (~(1 << i));
  return x;
}

/*
  Provided functions for bits by g++ compiler:
  __builtin_clz(x): numbers of zero at the beginning of the bits representation of the numbers.
  __builtin_ctz(x): numbers of zero at the end of the bits representation of the numbers.
  __builtin_popcount(x): numbers of ones in the number
  __builtin_parity(x): the parity(even or odd) of the numbers of ones.

  int x = 5328; // 00000000000000000001010011010000
  cout << __builtin_clz(x) << "\n"; // 19
  cout << __builtin_ctz(x) << "\n"; // 4
  cout << __builtin_popcount(x) << "\n"; // 5
  cout << __builtin_parity(x) << "\n"; // 1
*/

/*
  Bits can be used to represent set
  Set operations can be implemented as bits operations:
                  Set syntax      Bit syntax
  intersection    a ∩ b            a & b
  union           a ∪ b            a | b
  complement      bar(a)           ~a
  difference      a \ b            a & (~b)

  int x = (1<<1)|(1<<3)|(1<<4)|(1<<8);
  int y = (1<<3)|(1<<6)|(1<<8)|(1<<9);
  int z = x|y;
  cout << __builtin_popcount(z) << "\n"; // 6
*/

// Iterating through subsets of {0, 1, ..., n - 1}
FOR(b, 0, (1 << n) - 1) {
  // process subset b
}

// Goes through the subsets with exactly k elements:
FOR(b, 0, (1 << n) - 1) {
  if (__builtin_popcount(b) == k) {
    // process subset b
  }
}

// Goes through all subsets of a set x
long b = 0;
do {
  // process subset b
} while (b = (b - x) & x);
