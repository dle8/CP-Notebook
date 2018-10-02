/*
Author: Dung Tuan Le
University of Rochester
Created: 06/07/2018
*/

/*
Tested: https://www.spoj.com/problems/MST/
*/

struct DSU {//union based on height of the tree
	long lab[N];
	
	DSU() {
		FOR(i, 1, N) lab[i] = -1;
	}
	
	long getRoot(long u) {
		if (lab[u] < 0) return u;
		return lab[u] = getRoot(lab[u]);
	}
	
	bool merge(long u, long v) {
		long roota = getRoot(u); 
		long rootb = getRoot(v);
		if (roota == rootb) return false;
		if (lab[roota] == lab[rootb]) {
			lab[roota]--;
			lab[rootb] = roota;
			return true;
		}
		if (lab[roota] < lab[rootb]) lab[rootb] = roota;
		else lab[roota] = rootb;
		return true;
	}
};
