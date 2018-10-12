/*
Author: Dung Tuan Le
University of Rochester
Created: 11/10/2018
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> Point;
typedef pair<Point, Point> line;
struct strLine { ld a, b, c; };

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); } 
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 40+2

vector<pllll> firstHalf, secondHalf;
long w[maxn], v[maxn];
ll maxv[maxn];

long getBit(long i, long x) {//get the ith bit of x
	return ((x>>(i-1)) & 1);
}

bool cmp (const pllll&a, const pllll&b) {
	return (a.fi < b.fi);
}

long bs(ll key) {
	long d = 0;
	long c = secondHalf.size() - 1;
	while (d<=c) {
		long mid = (d+c)/2;
		if (secondHalf[mid].fi <= key) d = mid + 1;
		else c = mid - 1;
	}
	return c;
}

int main() {
	fio;
		
	long m, n;
	ll sumv, sumw;
	cin >> n >> m;
	FOR(i, 1, n) cin >> w[i] >> v[i];

	//divide into 2 smaller subsets. m/2 & (m - m/2) 
	long half = n/2;
	FOR(subSet, 0, (1<<half)-1) {
		sumv = 0;
		sumw = 0;
		FOR(i, 1, half) 
			if (getBit(i, subSet) == 1) {
				sumv += v[i];
				sumw += w[i];
			}
		if (sumw <= m) firstHalf.pb(mp(sumw, sumv));
	}
	
	FOR(subSet, 0, (1<<(n-half))-1) {
		sumv = 0;
		sumw = 0;
		FOR(i, 1, n-half)
			if (getBit(i, subSet) == 1) {
				sumv += v[i + half];
				sumw += w[i + half];
			}
		if (sumw <= m) secondHalf.pb(mp(sumw, sumv));
	}
	
	sort(secondHalf.begin(), secondHalf.end(), &cmp);
	maxv[0] = secondHalf[0].se;
	FOR(i, 1, secondHalf.size()-1) {
		maxv[i] = max(secondHalf[i].se, maxv[i-1]);
	}
	
	ll res = 0;
	FOR(i, 0, firstHalf.size()-1) {
		long tmp = bs(m - firstHalf[i].fi);
		if (tmp == -1) continue;
		res = max(res, firstHalf[i].se + maxv[tmp]);
	}	
	
	cout << res;
	return 0;
}
