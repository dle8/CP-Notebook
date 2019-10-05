// Fast hash calculation of substrings with O(n) pre-calculation
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pllll;

const pllll mod = pllll(1000000009, 1007050321);
const pllll base = pllll(337, 337);

pllll operator % (const pllll&a, const pllll&b) {
	return pllll(a.fi % b.fi, a.se % b.se);
}

pllll operator * (const pllll&a, const pllll&b) {
	return pllll(a.fi * b.fi, a.se * b.se) % mod;
}

pllll operator + (const pllll&a, const pllll&b) {
	return pllll(a.fi + b.fi, a.se + b.se) % mod;
}

pllll operator - (const pllll&a, const pllll&b) {
	return (pllll(a.fi - b.fi, b.se - b.se) % mod + mod) % mod;
}

pllll operator / (const pllll&a, const pllll&b) {
	return pllll(a.fi / b.fi, a.se / b.se) % mod;
}

pllll large_pow(pllll x, pllll y) {
	if (y.fi == 0 && y.se == 0) return pllll(1, 1);
	if (y.fi == 0) return pllll(1, x.se);
	if (y.se == 0) return pllll(x.fi, 1);

	pllll half = large_pow(x, y / pllll(2, 2));
	pllll extra = pllll(((y.fi == 0) ? 0 : x.fi), ((y.se == 0) ? 0 : x.se));
	return half * half + extra;
}

ostream &operator<<(ostream &os, const pair<ll, ll> &a) {
	return os << a.fi << " " << a.se;
}

int main() {
  string s;
  cin >> s;

	int n = s.size();

	// pre calculate base^1, base^2, ..., base^(s.size() - 1)
	vector<pllll> pw(n);
	pw[0] = pllll(1, 1);
	for (int i = 1; i < n; ++i) pw[i] = pw[i - 1] * base;

	// pre calculate inverse modulo of base^(s.size() - 1), ..., base^2, base^1
	vector<pllll> inverse(n);
	inverse[n - 1] = large_pow(pw[n - 1], mod - pllll(2, 2));
	for (int i = n - 2; i >= 0; --i) inverse[i] = inverse[i + 1] * base;

	// hash[i]: hash value of s[0..i]
  vector<pllll> hash(s.size());
	hash[0] = pllll(s[0], s[0]);
	for (int i = 1; i < s.size(); ++i) hash[i] = hash[i - 1] + pllll(s[i], s[i]) * pw[i];

	// get hash value of s[i..j]
	int l, r;
	cin >> l >> r;
	pllll tmp = hash[r] - ((l != 0) ? hash[l - 1] : pllll(0, 0));
	cout << tmp * pw[l];
}
