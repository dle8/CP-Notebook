/*
	Author: Dung Tuan Le
	University of Rochester
	Created: 11/27/2018
*/

/*
	Manacher algorithm returns the longest odd/ even length palindromes that are substrings of string s
	and have center i for all 0 <= i <= s.length - 1
*/

pair<vl, vl> manacher(string s) {
	long n = long(s.size());
	vl d1(n, 0);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		long k = (i > r) ? 1 : min(d1[l + r - i], r - i);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}

	vl d2(n, 0);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		long k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k;
		}
	}
	return mp(d1, d2);
}
