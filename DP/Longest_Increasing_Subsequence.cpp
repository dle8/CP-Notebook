/*
Author: Hung Duc Vu
Case Western Reserve University
Created: 10/10/2018
*/

/*
https://www.spoj.com/problems/LIS/
*/

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<r; i++)
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

#define maxN 100000+10

int main() {
	fio;
	long n;
    long a[maxN], f[maxN];
    memset(f, 0, sizeof(f));

	cin >> n;
	FOR(i, 0, n) cin >> a[i];

    if (n == 0) {
        cout << 0;
        return 0;
    }

    long res = 0;
    f[0] = a[0];

    FOR(i, 1, n) {
        long l = 0;
        long r = res;
        long mid = (l + r) / 2;
        while (l < r) {
            mid = (l + r) / 2;
            if (f[mid] >= a[i])
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (f[l] < a[i]) {
            f[l + 1] = a[i];
            res = max(res, l + 1);
        }
        else
            f[l] = a[i];
    }

	cout << res + 1;
	return 0;
}
