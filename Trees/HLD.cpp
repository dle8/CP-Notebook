#include <bits/stdc++.h>
#define oo 1e9
#define maxn 10000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

struct node {
	long v;
	node* next;
};

long n, nChain, parent[maxn], chainHead[maxn], nchild[maxn], tcount, treeFlattening[maxn], chainOf[maxn];
node* head[maxn];

void swap(long&a, long&b) {
	long temp = a;
	a = b;
	b = temp;
}

void findHV(long u) {//dfs lan tim so con cua moi thang
	long v, child;
	node* p = head[u];
	node* firstChild = nullptr;
	node* heavyVertex = new node;
	heavyVertex->v = n+1;
	while (p!=nullptr) {
		v = p->v;
		if (parent[v]==0) {
			if (firstChild==nullptr) firstChild = p;
			parent[v] = u;
			findHV(v);
			nchild[u]+=(nchild[v]+1);
			if (nchild[v]>nchild[heavyVertex->v]) heavyVertex = p;
		}
		p = p->next;
	}

	if (heavyVertex->v!=(n+1)) swap(firstChild->v, heavyVertex->v);//nho dau thg head[u]->v k phai la con cua u
}

void dfs2(long u) {
	tcount++;
	treeFlattening[tcount] = u;
	chainOf[u] = nChain;
	long v;
	node* p = head[u];

	long numth = 0;
	while (p!=nullptr) {
		v = p->v;
		if (parent[v]==u) {
			numth++;
			if (numth>=2) chainHead[++nChain] = v;
			dfs2(v);
		}
		p = p->next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v;
	node* p;
	cin >> n;
	FOR(i, 1, n-1) {
		cin >> u >> v;
		p = new node;
		p->v = v;
		p->next = head[u];
		head[u] = p;

		p = new node;
		p->v = u;
		p->next = head[v];
		head[v] = p;
	}

	memset(nchild, 0, sizeof(nchild));
	parent[1] = -1;
	findHV(1);
	tcount = 0;
	nChain = 1;
	chainHead[1] = 1;
	dfs2(1);
	FOR(i, 1, tcount) cout << treeFlattening[i] << " ";
	cout << endl;
	FOR(i, 1, n) cout << i << " " << chainOf[i] << endl;
	return 0;
}
