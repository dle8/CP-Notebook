/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 23/11/2018
*/

/*
  Note: This function returns number of roots a quadratic equation has, and the roots(if number of roots > 0)
  Modify root calculation to avoid catastrophic cancellation.
*/

typedef long double ld;

int quadRoots(ld a, ld b, ld c, pair<ld, ld> &out) {
  assert(a != 0);
  ld delta = b * b - 4 * a * c;
  if (delta < 0) return 0;
  ld sum = (b >= 0) ? (-b - sqrt(delta)) : (-b + sqrt(delta));
  out = {sum / (2 * a), (sum == 0) ? 0 : (2 * c) / sum};
  return 1 + (delta > 0);
}
