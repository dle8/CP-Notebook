/*
Author: Dung Tuan Le
University of Rochester
*/

/*
 Calculating the number of distinct ways to fill an n× m grid using 1×2 and 2×1 size tiles.
*/
#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
typedef long long ll;
typedef long double ld;

const double pi = 3.141592653589793;

ll countingTilings(long n, long m) {
	ld res = 1.0;
	
	FOR(a, 1, n/2)
	FOR(b, 1, m/2) {
		res *=  (4 * (pow(cos((pi * a)/double(n + 1)), 2) + pow(cos((pi * b)/double (m + 1)), 2)));
	}
	
	return ll(res);
}

