/*
Author: Dung Tuan Le
University of Rochester
Created: 01/08/2019
*/

/*
Tested:
https://www.spoj.com/problems/TRAFFICN/
https://www.spoj.com/problems/MELE2/
*/

#define oo 1e9

struct edge {
	int v, c, next;
};

edge road[M];

class pq {//customize the priority_queue to avoid adding the same vertice with different distances.
	public:
		int heap[N], indexOf[N];
		//indexOf[i]: index of vertice i in the heap. Indicate that whether vertice i is in the heap or not.
		int heapSize;
	
	pq() {
		heapSize = 0;
		memset(indexOf, 0, sizeof(indexOf));
	}
	
	~pq() {}
	
	void add(int k) {
		if (indexOf[k]==0) {
			heap[++heapSize] = k;
			indexOf[k] = heapSize;
		}
		upHeap(heapSize);
	}
	
	void upHeap(int index) {
		long tmp = heap[index];
		while (true) {
			long parent = index/2;//the index of the parent node
			if ((parent == 0) || d[heap[parent]] <= d[tmp]) break;//if (stand in root or stand in the right place in heap)
			heap[index] = heap[parent];
			indexOf[heap[index]] = index;
			index = parent;
		}
		heap[index] = tmp;
		indexOf[heap[index]] = index;
	}
	
	int peek() {
		return heap[1];
	}
	
	bool empty() {
		return (heapSize == 0);//heap is empty
	}
	
	void poll() {
		indexOf[heap[1]] = 0;
		heap[1] = heap[heapSize--];
		indexOf[heap[1]] = 1;
		downHeap(1);
	}
	
	void downHeap(int index) {
		long tmp = heap[index];
		while (true) {
			long child = index*2;//left child
			if (child < heapSize && d[heap[child]] > d[heap[child+1]]) child++;//choose the smallest child among the two
			if (child > heapSize || d[tmp] <= d[heap[child]]) break;//if (has no child or stand in the right place in the heap)
			heap[index] = heap[child];
			indexOf[heap[index]] = index;
			index = child;
		}
		heap[index] = tmp;
		indexOf[heap[index]] = index;
	}
};

long dijkstra(long source, long dst) {
	FOR(u, 1, N) d[u] = oo;
	d[source] = 0;
	
	pq q;
	q.add(source);
	while (!q.empty()) {
		u = q.peek();
		q.poll();
		
		int i = head[u];
		while (i!=0) {
			v = road[i].v;
			if (d[v] > d[u] + road[i].c) {
				d[v] = d[u] + road[i].c;
				q.add(v);
			}
			i = road[i].next;
		}
	}
	
	return d[dst];	
}

