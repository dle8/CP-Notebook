/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 11/23/2018
*/

/*
  Return (if exist) the intersection(s) for 2 circles with center c1, c2 and radii r1, r2 respectively.
*/

typedef long double ld;

bool circleCirle(Point c1, ld r1, Point c2, ld r2, pair<Point, Point> &intersections) {
  ld d = abs(c2 - c1), cosa = (d * d + r1 * r1 - r2 * r2) / (2 * d * r1);
  if (abs(cosa) > 1) return false; // 2 circles dont intersect another
  ld alpha = acos(cosa);
  Point rad = (c2 - c1) / d * r1; // vector c1c2 is resized to have length d
  intersections = {c1 + rot(rad, -alpha), c1 + rot(rad, alpha)};
  return true;
}
