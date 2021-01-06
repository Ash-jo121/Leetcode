class MedianFinder {
public:
	/** initialize your data structure here. */
	priority_queue<int> maxHeap;
	priority_queue<int, greater<int> > minHeap;

	MedianFinder() {
		maxHeap.clear();
		minHeap.clear();
	}

	void addNum(int num) {
		maxHeap.push(num);
		int x = maxHeap.top();
		maxHeap.pop();
		minHeap.push(x);
		if (minHeap.size() > maxHeap.size()) {
			int y = minHeap.top();
			minHeap.pop();
			maxHeap.push(y);
		}
	}

	double findMedian() {
		if (maxHeap.size() > minHeap.size()) {
			return double(maxHeap.top());
		}

		if (maxHeap.size() == minHeap.size()) {
			double value = double(maxHeap.top()) + double(minHeap.top()) / 2.0;
			return value;
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */