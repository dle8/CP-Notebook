/*
Author: Dung Tuan Le
University of Rochester
Created: 06/12/2018
*/

/*
Tested: https://www.spoj.com/problems/LCA/
*/

struct node {
	long v, next;
};

long n, height[maxn], euler[10*maxn], head[maxn], fa[maxn];
long it[10000+10];
node graph[maxn];

long min(long a, long b) {
	if (height[a]<height[b]) return a;
	else return b;
}

void update(long cs, long u, long v, long i) {
	if (i<u || v<i) return;
	it[cs] = min(it[cs], euler[i]);
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*cs, u, mid, i);
	update(2*cs+1, mid+1, v, i);
}

long getLca(long cs, long u, long v, long l, long r) {
	if(r<u || v<l) return 0;
	if (l<=u && v<=r) return it[cs];
	long mid = (u+v)/2;
	long left = getLca(2*cs, u, mid, l, r);
	long right = getLca(2*cs+1, mid+1, v, l, r);
	return min(left, right);
}

void dfs(long u, long &count) {
	long v;
	long i = head[u];
	count++;
	fa[u] = count;
	euler[count] = u;
	while (i!=0) {
		v = graph[i].v;
		height[v] = height[u]+1;
		dfs(v, count);
		count++;
		euler[count] = u;
		i = graph[i].next;
	}
	count++;
	euler[count] = u;
}

//getLca(1, 1, count, fa[s], fa[t])

