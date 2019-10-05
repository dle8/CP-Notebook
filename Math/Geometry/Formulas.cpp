/*
Author: Dung Tuan Le
University of Rochester
Created: 06/10/2018
*/

#define x first
#define y second
#define eps 1e-9

typedef long double ld;
typedef pair<ld, ld> Point;
typedef pair<point, point> Line;

struct strLine {
	ld a, b, c;// ax + by + c
};

// Return a straight line ax + by + c that passes throught p1 and p2 in (x, y) coordinate
strLine getStrLine(Point p1, Point p2) {
	strLine sLine;
	sLine.a = p1.y - p2.y;
	sLine.b = p2.x - p1.x;
	sLine.c = p1.x * p2.y - p2.x * p1.y;
	return sLine;
}

// Distance between 2 points
ld distanceBetween(Point p1, Point p2) {
	return (sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}

// Distance between point p1 and d(x): ax + by + c = 0
ld distanceBetween(Point p1, strLine sline) {
	return ((sline.a * p1.x + sline.b * p1.y + sline.c) / (ld (pow(sline.a, 2) + pow(sline.b, 2))));
}

// Cosin of angle between 2 straight lines a1x + b1y + c1 = 0 and a2x + b2y + c2 = 0:
ld cosin_angle(strLine y1, strLine y2) {
	ld numerator = abs(y1.a * y2.a + y1.b * y2.b);
	ld denumerator = sqrt(pow(y1.a, 2) + pow(y1.b, 2)) * sqrt(pow(y2.a, 2) + pow(y2.b, 2));
	return numerator / denumerator;
}

// Check if p1(x1, y1) and p2(x2, y2) belongs to different side of ax1 + bx1 + c
bool diff_side(Point p1, Point p2, strLine l) {
	return (l.a * p1.x + l.b * p1.y + l.c) * (l.a * p2.x + l.b * p2.y + l.c) < 0;
}

// Check if p1(x1, y1) lies in the line that goes through p2(x2, y2), p3(x3, y3)
bool in_line(Point p1, Point p2, Point p3) {

}

// Return -1 if 2 lines l1 and l2 are parallel, 0 if they are overlap, 1 and the intersection
// point if they intersect.
int is_intersect(strLine l1, strLine l2, Point &p) {
	ld d = l1.a * l2.b - l2.a * l1.b;
	ld dx = l1.b * l2.c - l2.b * l1.c;
	ld dy = l1.a * l2.c - l2.a * l1.c;
	if (d != 0) {
		p1 = {dx / d, dy / d};
		return 1;
	}
	if (dx != 0 || dy != 0) return 0;
	return -1;
}

// ccw: return the directions of going from A to B to C.
// Return -1 if turn right, 1 if turn left, 0 if go straight
long ccw(Point p1, Point p2, Point p3) {
	ld u1 = p2.x - p1.x;
	ld v1 = p2.y - p1.y;
	ld u2 = p3.x - p2.x;
	ld v2 = p3.y - p2.y;

	ld t = u1 * v2 - v1 * u2;
	if (abs(t) < eps) return 0;
	if (t>0) return 1;
	return -1;
}

// Pick theorem: Area of the polygon constructed on a grid of equal-distanced
// points(points with integer coordinates) such that all the polygon's vertices
// are grid points.
ld areaOfPoly(int interrior_point, int boundary_point) {
	return interrior_point + boundary_point / 2 - 1;
}

ld areaOfPoly(Point vertices[N]) {
	vertices[N+1] = vertices[1];

	ld area = 0.0;
	FOR(i, 1, N) {
		area+= ((vertices[i].x - vertices[i+1].x) * (vertices[i].y - vertices[i+1].y) / ld(2));
	}
	return area;
}
