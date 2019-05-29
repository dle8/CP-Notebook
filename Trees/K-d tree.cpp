/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define sz(x) int(x.size())

using namespace std;

typedef long long ll;
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

const ll k = 2;
const ll inf = 1e18;

struct Point {
	ll x, y;

	Point() {}
	Point(ll x, ll y): x(x), y(y) {}
};

ostream& operator<<(ostream&os, Point p) {
	return os << p.x << " " << p.y;
}

bool operator==(const Point&a, const Point&b) {
	return a.x == b.x && a.y == b.y;
}

bool on_x(const Point&a, const Point&b) {
	return a.x < b.x;
}

bool on_y(const Point&a, const Point&b) {
	return a.y < b.y;
}

ll manhattan(const Point&a, const Point&b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

struct bbox {
	ll x0, x1, y0, y1;

	bbox(): x0(inf), x1(-inf), y0(inf), y1(-inf) {}

	void compute(const vector<Point> &v) {
		for (int i = 0; i < v.size(); i++) {
			x0 = min(x0, v[i].x); x1 = max(x1, v[i].x);
			y0 = min(y0, v[i].y); y1 = max(y1, v[i].y);
		}
	}

	// distance from a point to this box
	ll distance(const Point&p) {
		if (p.x < x0) {
			if (p.y < y0) return manhattan(Point(x0, y0), p);
			else if (p.y > y1) return manhattan(Point(x0, y1), p);
			else return manhattan(Point(x0, p.y), p);
		}
		else if (p.x > x1) {
			if (p.y < y0) return manhattan(Point(x1, y0), p);
			else if (p.y > y1) return manhattan(Point(x1, y1), p);
			else return manhattan(Point(x1, p.y), p);
		}
		else {
			if (p.y < y0) return manhattan(Point(p.x, y0), p);
			else if (p.y > y1) return manhattan(Point(p.x, y1), p);
			else return 0; // inside the box
		}
	}
};

// store a single node of the kd-tree
struct kdnode {
	bool leaf; // determine whether this's a leaf node
	Point point; // the single point of this's a leaf
	bbox bound; // bounding box for set of points in children

	kdnode *left, *right; // two children of this kd-node

	kdnode() {
		this->leaf = false;
		this->left = NULL;
		this->right = NULL;
	}
	~kdnode() {
		if (left) delete(left);
		if (right) delete(right);
	}

	// intersect a point with this node
	ll intersect(const Point &p) {
		return bound.distance(p);
	}

	// construct a kd-tree from a given cloud of points
	void construct(vector<Point> &vp) {
		// compute bounding box for points at this node
		bound.compute(vp);
		// this's a leaf node
		if (sz(vp) == 1) {
			leaf = true;
			point = vp[0];
		}
		else {
			// split on x if the bbox is wider than high
			if (bound.x1 - bound.x0 >= bound.y1 - bound.y0) {
				sort(vp.begin(), vp.end(), on_x);
			}
			// otherwise
			else sort(vp.begin(), vp.end(), on_y);
			// divide by taking half the array for each child
			ll half = sz(vp) / 2;
			vector<Point> vl(vp.begin(), vp.begin() + half);
			vector<Point> vr(vp.begin() + half, vp.end());
			left = new kdnode(); left->construct(vl);
			right = new kdnode(); right->construct(vr);
		}
	}
};

struct kdtree {
	kdnode *root;

	// construct kd-tree from points
	kdtree(const vector<Point> &vp) {
		vector<Point> v(vp.begin(), vp.end());
		root = new kdnode();
		root->construct(v);
	}

	~kdtree() {
		if (root) delete(root);
	}

	// search nearest point
	ll search(kdnode* node, const Point&p) {
		if (node->leaf) {
			// cout << node->point << '\n';
			return manhattan(p, node->point);
		}
		ll left = node->left->intersect(p);
		ll right = node->right->intersect(p);

		// choose the side with closet bounding box to search
		// search the other side if needed
		ll best = inf;
		if (left < right) {
			best = search(node->left, p);
			if (right < best) best = min(best, search(node->right, p));
		}
		else {
			best = search(node->right, p);
			if (left < best) best = min(best, search(node->left, p));
		}
		return best;
	}

	ll nearest(const Point&p) {
		return search(root, p);
	}
};

int main() {
	// fio;
	// freopen("input.txt", "r", stdin);
	ll n; cin >> n;
	vector<Point> vp;
	for (int i = 1; i <= n; i++) {
		ll x, y;
		cin >> x >> y;
		vp.push_back(Point(x, y));
	}
	// fclose(stdin);
	kdtree tree(vp);
	for (Point &p: vp) {
		cout << tree.nearest(p) << '\n';
	}
	// cout << tree.nearest(Point(-2, 0));
	return 0;
}
