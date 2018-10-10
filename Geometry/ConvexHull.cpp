/*
Author: Dung Tuan Le
University of Rochester
Created: 10/09/2018
*/

/*
Tested: https://vn.spoj.com/problems/MILITARY/
*/

typedef vector<Point> vp;

bool cw(Point a, Point b, Point c) { // a->b->c a turns right at b
  	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(Point a, Point b, Point c) { // a->b->c a turns left at b
  	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

/*bool linear(Point a, Point b, Point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) == 0;
}*/

vp convexHull(vector<Point> &a) {
	sort(a.begin(), a.end(), &cmp);
	
	Point p1 = a[0]; Point p2 = a.back();
	
	vp up, down;
	up.pb(p1);
	down.pb(p1);
	
	for (size_t i=1; i<a.size(); ++i) {
		if (i == a.size()-1 || cw(p1, a[i], p2)) {//tinh ca nhung diem thang hang
			while (up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], a[i])) up.pop_back();
			up.pb(a[i]);
		}
		
		if (i == a.size()-1 || ccw(p1, a[i], p2)) {
			while (down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], a[i])) down.pop_back();
			down.pb(a[i]);
		}
	}
	
	vp convexHull;
	for (size_t i = 0; i<up.size(); i++)
		convexHull.pb(up[i]);
	
	for (size_t i = down.size()-2; i>0; --i)
		convexHull.pb(down[i]);
	
	return convexHull;
}
