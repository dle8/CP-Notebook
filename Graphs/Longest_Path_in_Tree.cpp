/*
Author: Dung Tuan Le
University of Rochester
Created: 08/16/2018
*/

/*
Find the longest path in a given tree.
Idea: Choose an arbitrary vertice u (in here the choosen vertice is 1), use dfs to find
the longest path from that vertice, ending in, for example, v. Dfs a second time from v
to find the longest path from v, ending in k. Then, the longest path in the tree is the path from
u to k.
*/

struct node{
	long v, next;
};

void dfs(long u, long tlength) {
	bool isLeaf = true;
	long v;
	long i = head[u];
	check[u] = false;
	while (i!=0) {
		v = graph[i].v;
		if (check[v]) {
			isLeaf = false;
			dfs(v, tlength+1);
		}
		i = graph[i].next;
	}
	if (isLeaf && tlength>longestLength) {
		farthestP = u;
		longestLength = tlength;
	}
}


/*
	memset(check, true, sizeof(check));
	longestLength = 0;
	dfs(1, 0);
	longestLength = 0;
	memset(check, true, sizeof(check));
	dfs(farthestP, 0);
	cout << longestLength;
*/
