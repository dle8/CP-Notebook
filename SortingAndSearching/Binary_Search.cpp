/*
  Author: Dung Tuan Le
  University of Rochester
  Created: 08/29/2018
*/

/*
  Find a position for a number given required features in sorted vector, whose
  elements indexed from 0 to 1.
*/

#include <bits/stdc++.h>

/*
bool cmp() {
  //custom compare code goes here.
}
*/

sort(a.begin(), a.end(), &cmp);

// Find the index of the first element that equals to or larger than to value "key"
// In case of all elements in a will smaller than key -> this func returns a.size(), or n + 1
long bs(vector<long> a, long key) {
  long d = 0;
  long c = a.size() - 1;

  while (d <= c) {
    long mid = (d + c)/2;
    if (a[mid] >= key) c = mid - 1;
    else d = mid + 1;
  }
  return d;
}

// Find the index of the last element that equals to or smaller than value "key"
// In case of all elements in a will larger than key -> this funcs return -1
long bs(vector<long> a, long key) {
  long d = 0;
  long c = a.size() - 1;

  while (d <= c) {
    long mid = (d + c)/2;
    if (a[mid] <= key) d = mid + 1;
    else c = mid - 1;
  }
  return c;
}
