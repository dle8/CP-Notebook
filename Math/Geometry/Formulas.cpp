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
	return ((sline.a * p1.x + sline.b * p1.y + sline.c) / (double (pow(sline.a, 2) + pow(sline.b, 2))));
}

// Cosin of angle between 2 straight lines y = a1x + b1y + 


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

ld areaOfPoly(Point vertices[N]) {
	vertices[N+1] = vertices[1];
	
	ld area = 0.0; 
	FOR(i, 1, N) {
		area+= ((vertices[i].x - vertices[i+1].x) * (vertices[i].y - vertices[i+1].y) / double(2));
	}
	return area;
}
