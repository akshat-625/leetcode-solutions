class MedianFinder {
public:
    priority_queue<int> pq1, pq2;

    MedianFinder() {}
    
    void addNum(int num) {
        if (pq1.empty()) {
            pq1.push(num);
            return;
        }

        if (num > pq1.top()) {
            pq2.push(-num);
        } else {
            pq1.push(num);
        }

        if ((int)pq1.size() - (int)pq2.size() > 1) {
            pq2.push(-pq1.top());
            pq1.pop();
        } else if (pq2.size() > pq1.size()) {
            pq1.push(-pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        if (pq1.empty()) {
            return 0;
        }
        if (pq1.size() > pq2.size()) {
            return pq1.top();
        }
        return (pq1.top() - pq2.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */