/*
Author: Dung Tuan Le
University of Rochester
Created: 05/06/2018
*/

//return an vector of size N - with N is length of string s
//the i-th element of this vector is the length of longest prefix of s that starts in s[i].
vector<long> z(string s) {
	long l, r;
	long N = s.length();
	
	vector<long> ans(N);
	ans[0] = N;
	l = r = 0;
	FOR(i, 1, N-1) {
		if (i>r) {
			l = i; r = i-1;
			FOR(j, i, N-1) if (s[j-i]==s[j]) r = j; else break;
			ans[i] = r-l+1;
		}
		else {
			long k = i-l;
			if (ans[k]<=r-i) ans[i] = ans[k];
			else {
				l = i;
				FOR(j, r+1, N-1) if (s[j-i]==s[j]) r = j; else break;
				ans[i] = r-l+1;
			}
		}
	}
	return ans;
}
