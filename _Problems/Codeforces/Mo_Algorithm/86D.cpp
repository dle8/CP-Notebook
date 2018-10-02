#include <bits/stdc++.h>
#define maxv 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define oo 1e9
using namespace std;

struct que {
	long l, r, pos;
};

que query[maxv];
long a[maxv], sqrtn, res[maxv], occurence[maxv], tmax, n, q;
set<long> s[maxv];
set<long>::iterator it;

bool cmp(const que&a, const que&b) {
	if (a.l/sqrtn!=b.l/sqrtn) return a.l/sqrtn<b.l/sqrtn;
	return a.r<b.r;
}

//s[i] contains all integers whose appears in the array for i times.
//tmax is the most appearance time of an integer. 

void add(long v) {
	s[occurence[v]].erase(v);
	occurence[v]++;
	s[occurence[v]].insert(v);
	if (occurence[v]>tmax) tmax = occurence[v];
}

void del(long v) {
	s[occurence[v]].erase(v);
	occurence[v]--;
	s[occurence[v]].insert(v);
	if (s[tmax].empty()) tmax--;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, q) {
		cin >> query[i].l >> query[i].r;
		query[i].pos = i;	
	}
	sqrtn = sqrt(n);
	sort(query+1, query+1+q, cmp);

	tmax = -oo;
	FOR(i, query[1].l, query[1].r) add(a[i]);
	
	cout << tmax << "\n";
	for (it=s[tmax].begin(); it!=s[tmax].end(); ++it) {
		res[query[1].pos] = *it;
		break;
	}

	FOR(i, 2, q) {
		FOR(j, query[i-1].l, query[i].l-1) del(a[j]);
		FOR(j, query[i].l, query[i-1].l-1) add(a[j]);
		FOR(j, query[i-1].r+1, query[i].r) add(a[j]);
		FOR(j, query[i].r+1, query[i-1].r) del(a[j]);
		for (it=s[tmax].begin(); it!=s[tmax].end(); ++it) {
			res[query[i].pos] = *it;
			break;
		}
	}
	
	FOR(i, 1, q) cout << res[i] << "\n";
	
	return 0;
}
