/*
Author: Dung Tuan Le
University of Rochester
Created: 10/10/2018
*/

/*
Tested: https://www.spoj.com/problems/KNAPSACK/
*/

/*
Given a weight w and n objects. Each objects i has weight w[i] and value v[i]. Pick subset of objects from the given n objects that
their total weight does not exceed w and their total value is maximized.
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

#define maxn 2000+10
#define maxs 2000+10

long tsize[maxn], value[maxn], maxValue[maxs];
bool possible[maxs];

int main() {
	fio;

	long s, n;

	cin >> s >> n;
	FOR(i, 1, n) cin >> tsize[i] >> value[i];
	
	memset(possible, false, sizeof(possible));
	memset(maxValue, 0, sizeof(maxValue));

	possible[0] = true;
	FOR(k, 1, n)
	REP(w, s, 0) {
		if (possible[w] && w + tsize[k] <= s) {
			possible[w + tsize[k]] = true;
			maxValue[w + tsize[k]] = max(maxValue[w + tsize[k]], maxValue[w] + value[k]);
		}
	}
	
	long res = 0;
	FOR(i, 1, s) res = max(res, maxValue[i]);
	
	cout << res;
	return 0;
}
