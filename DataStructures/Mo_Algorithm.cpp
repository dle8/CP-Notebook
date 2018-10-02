/*
Author: Dung Tuan Le
University of Rochester
Created: 07/07/2018
*/

/*
Problem: Given an array A and a set of queries. Each query contains a pair of positive number (i,j), asking to find some characteristics
of the sub-array of A that starts from the i-th element of A and ends in the j-th element of A

In order to reduce the time complexity, Mo's algorithm rearranges the order in which we consider an query so that
the overall complexity is O((N+M)*sqrt(N)), with N is the number of element in A and M is the number of query.
*/

/*
Tested:
http://codeforces.com/contest/86/problem/D <You can see demonstration of this code in _Problems>
*/

long sn = sqrt(n);

struct Query {
	long l, r;
};

bool cmp(const Query&x, const Query&y) {
	if (x.l/sn != y.l/sn) return ((x.l/sn) < (y.l/sn));
	return x.r < y.r;
}

