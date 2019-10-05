/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 11/21/2018
*/

/*
  Tested: Google Code Jam Kickstart 2018 round H, problem C. Let me count the ways
  https://codejam.withgoogle.com/codejam/contest/3324486/dashboard#s=p2
*/

/*
  Time complexity: O(nlog p)
*/

const long p = 1000000007;

typedef long long ll;

long POW(long x, long y) { // fast way to calculate x^y in log(y) mod p
  if (y == 0) return 1;
  if (y == 1) return x % p;
  long half = POW(x, y / 2);
  if (y % 2 == 0) return (1LL * half * half) % p;
  return ((1LL * half * half) % p) * x * 1LL) % p;
}

long factorial(long x) {
  long fact = 1;
  for (int i = 1; i <= x; i++) fact = (1LL * fact * i) % p;
  return fact;
}

ll c(long n, long k) {
  long x = factorial(n);
  long y = (1LL * factorial(n - k) * factorial(k)) % p;
  y = POW(y, p - 2);
  return ((1LL * x * y) % p + p) % p; // in case (x * y) % p is negative
}
