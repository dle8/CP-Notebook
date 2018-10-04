/*
Author: Dung Tuan Le
University of Rochester
Created: 04/10/2018
*/

/* Nim game: A and B are two players, with A takes the first turn. Each person can only take 1, k, or L coins each turn.
Given m queries, each queries contains the number of coins the table. For each queries, output whether who will win no matter which moves
the other will take. If A wins, output 'A', else ouput 'B' if B wins.*/

#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

const long maxn = 1e6;

char f[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long n, k, l, m;
	cin >> k >> l >> m;
	
	if (k>l) {
		long tmp = k;
		k = l;
		l = tmp;
	}
	
	f[0] = 'B';
	FOR(i, 1, k-1) {
		if ((i % 2) != 0) f[i] = 'A';
		else f[i] = 'B';
	} 
	
	FOR(i, k, l-1) {
		if (f[i-1] == 'A' && f[i-k] == 'A') f[i] = 'B';
		else f[i] = 'A';
	}
	
	FOR(i, l, maxn) {
		if (f[i-1] == 'A' && f[i-k] == 'A' && f[i-l] == 'A') f[i] = 'B';
		else f[i] = 'A';
	}
	
	FOR(i, 1, m) {
		cin >> n;
		cout << f[n];
	}
	return 0;
}
