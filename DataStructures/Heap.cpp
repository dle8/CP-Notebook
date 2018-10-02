/*
Author: Dung Tuan Le
University of Rochester
Created: 12/07/2017
*/

//This is an min heap: the top element of the heap is the minimum element.

class pq {//customize the priority_queue to avoid adding the same vertice with different distances.
	public:
		int heap[N];
		//indexOf[i]: index of vertice i in the heap. Indicate that whether vertice i is in the heap or not.
		int heapSize;
	
	pq() { heapSize = 0; }
	
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
			if ((parent == 0) || heap[parent] <= tmp) break;//if (stand in root or stand in the right place in heap)
			heap[index] = heap[parent];
			index = parent;
		}
		heap[index] = tmp;
	}
	
	int peek() {
		return heap[1];
	}
	
	bool empty() {
		return (heapSize == 0);//heap is empty
	}
	
	void poll() {
		heap[1] = heap[heapSize--];
		downHeap(1);
	}
	
	void downHeap(int index) {
		long tmp = heap[index];
		while (true) {
			long child = index*2;//left child
			if (child < heapSize && heap[child] > heap[child+1]) child++;//choose the smallest child among the two
			if (child > heapSize || tmp <= heap[child]) break;//if (has no child or stand in the right place in the heap)
			heap[index] = heap[child];
			index = child;
		}
		heap[index] = tmp;
	}
};
