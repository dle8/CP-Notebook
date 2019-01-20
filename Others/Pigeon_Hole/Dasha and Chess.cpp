/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define lb lower_bound
#define ub upper_bound
#define sz(x) int(x.size())
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

const double pi = 3.141592653589793;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

/* tach xau
string str = "Hello World"; stringstream ss(str);
while (ss >> token) cout << token << endl;
*/

const pll center = {500, 500};
pll king, rook[667];
long checkx[999 + 10], checky[999 + 10], r1, r2, r3, r4;
bool occupied[999 + 10][999 + 10];

inline void moveX(pll& a) {
	if (a.x < center.x) a.x++;
	else a.x--;
}

inline void moveY(pll& a) {
	if (a.y < center.y) a.y++;
	else a.y--;
}

inline bool inRange1(pll a) {
	return (a.x <= 499 && a.y <= 499);
}

inline bool inRange2(pll a) {
	return (a.x >= 501 && a.y <= 499);
}

inline bool inRange3(pll a) {
	return (a.x >= 501 && a.y >= 501);
}

inline bool inRange4(pll a) {
	return (a.x <= 499 && a.y >= 501);
}

int main() {
#ifdef _TIME
  //freopen("", "r", stdin);
  long tt = clock();
#endif

	fio;
	cin >> king.x >> king.y;
	FOR(i, 1, 666) {
		cin >> rook[i].x >> rook[i].y;
		checkx[rook[i].x]++;
		checky[rook[i].y]++;
		occupied[rook[i].x][rook[i].y] = true;
		if (inRange1(rook[i])) r1++;
		else if (inRange2(rook[i])) r2++;
		else if (inRange3(rook[i])) r3++;
		else r4++;
	}
	bool arriveAtCenter = (king == center);
	bool move1 = false, move2 = false, move3 = false, move4 = false;
	while (true) {
		if (!arriveAtCenter) {
			if (king.x == center.x) moveY(king);
			else moveX(king);
			if (king == center) arriveAtCenter = true;
		}
		else {
			if (!(move1 || move2 || move3 || move4)) {
				long leastRook = min(r1, min(r2, min(r3, r4)));
				if (leastRook == r1) move3 = true;
				else if (leastRook == r2) move4 = true;
				else if (leastRook == r3) move1 = true;
				else move2 = true;
			}
			if (move1) {
				if (!occupied[king.x - 1][king.y - 1]) king.x--, king.y--;
				else king.x--;
			}
			else if (move2) {
				if (!occupied[king.x + 1][king.y - 1]) king.x++, king.y--;
				else king.x++;
			}
			else if (move3) {
				if (!occupied[king.x + 1][king.y + 1]) king.x++, king.y++;
				else king.x++;
			}
			else {
				if (!occupied[king.x - 1][king.y + 1]) king.x--, king.y++;
				else king.x--;
			}
		}
		cout << king.x << " " << king.y << '\n';
		cout.flush();
		if (checkx[king.x] != 0 || checky[king.y] != 0) break; // get checked by a rook
		long k, x, y;
		cin >> k >> x >> y;
		if (k == -1 && x == -1 && y == -1) break; // computer move gets the king in check
		if (k == 0 && x == 0 && y == 0) break; // WA :(
		checkx[rook[k].x]--;
		checky[rook[k].y]--;
		occupied[rook[k].x][rook[k].y] = false;
		if (inRange1(rook[k])) r1--;
		else if (inRange2(rook[k])) r2--;
		else if (inRange3(rook[k])) r3--;
		else r4--;
		rook[k] = {x, y};
		checkx[rook[k].x]++;
		checky[rook[k].y]++;
		occupied[rook[k].x][rook[k].y] = true;
		if (inRange1(rook[k])) r1++;
		else if (inRange2(rook[k])) r2++;
		else if (inRange3(rook[k])) r3++;
		else r4++;
	}


#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif

	return 0;
}
