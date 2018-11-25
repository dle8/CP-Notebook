/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 08/22/2018
*/

/*
  Ternary Search: find the maximum value of function f(x) that is unimodal
  by dividing the range into 3 sub-ranges: [l, x1], (x1, x2), [x2, e]
*/

/* This func finds the maximum value of f(x) that increases, attains the maximum,
  and then decreases.
*/

double TernarySearch() {
  long l = 0;
  long r = f.size() - 1;

  long loopTimes = 100;
  FOR(i, 1, loopTimes) {
    double x1 = l + (r - l) / 3.0;
    double x2 = r - (r - l) / 3.0;

    if (f(x1) > f(x2)) r = x2;
    else l = x1;
  }

  return f(l);
}
