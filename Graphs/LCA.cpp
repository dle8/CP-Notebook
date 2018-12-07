/*
Author: Dung Tuan Le
University of Rochester
Created: 06/12/2018
*/
struct node {
	long v;
	node* next;
};

void dfs(long u) {//construct the tree
	long v;
	node* p = head[u];
	while (p!=nullptr) {
		v = p->v;
		if (parent[v]==0) {
			parent[v] = u;
			height[v] = height[u]+1;
			dfs(v);
		}
		p = p->next;
	}
}

void initLCA() {//initiate LCA
	FOR(u, 1, n) tnext[u][0] = parent[u];
	
	FOR(i, 1, int(log(n)/log(2)))
	FOR(u, 1, n) {
		if (tnext[tnext[u][i-1]][i-1]>0) tnext[u][i] = tnext[tnext[u][i-1]][i-1]; 
	}
}

long LCA(long u, long v) {//find the LCA between u & v
	if (height[u]<height[v]) {
		long tmp = u;
		u = v;
		v = tmp;
	}
	
	REP(i, int(log(height[u]-height[v])/log(2)), 0) {
		if (height[tnext[u][i]]>=height[v]) 
		u = tnext[u][i];	
	}
	
	if (u==v) return u;
	
	REP(i, int(log(height[u]-1)/log(2)), 0) {
		if (tnext[u][i]!=tnext[v][i]) {
			u = tnext[u][i];
			v = tnext[v][i];
		}
	}
	
	return tnext[u][0];
}

long distanceBetween(long u, long v) {
	return height[u] + height[v] - 2 * height[lca(u, v)];
}

void clr(node* p) {
	if (p->next!=nullptr) clr(p->next);
	delete p;
}

void clr() {
	FOR(i, 1, maxn) clr(head[i]);	
}

/*
Tested: 
https://www.spoj.com/problems/LCA/
*/
