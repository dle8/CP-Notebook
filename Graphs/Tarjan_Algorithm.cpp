#include <iostream>
#include <stack>
#include <string.h>
#define maxn 10000+10
#define maxm 100000+10
using namespace std;

struct node {
	long v, next;
};

node graph[maxm];
long n, m, count, component;
bool inGraph[maxn];//boolean array to mark the vertices that belong to founded scc
stack<int> Stack;
int number[maxn], low[maxn], head[maxn];

void dfs(long u) {
	long v;
	count++;
	number[u] = count;
	low[u] = number[u];
	Stack.push(u);
	long i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (inGraph[v]) {
			if (number[v]!=0) low[u] = min(low[u], number[v]);
			else {
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
		}
		i = graph[i].next;
	}

	if (low[u]==number[u]) {
		component++;
		do {
			v = Stack.top();
			Stack.pop();
			inGraph[v] = false;
		} while (v!=u);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v;
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		graph[i].v = v;
		graph[i].next = head[u];
		head[u] = i;
	}

	count = 0;//count variable to denote the order of visiting the vertices
	component = 0;
	memset(inGraph, true, sizeof(inGraph));

	for (int i=1; i<=n; i++)
		if (number[i]==0) dfs(i);//if i doesnt belong to any scc -> dfs into the tree roots i to find scc

	cout  << component;
	return 0;
}
