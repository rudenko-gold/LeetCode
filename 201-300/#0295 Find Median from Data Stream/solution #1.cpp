class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() : mid(data.end()) {
        
    }
    
    void addNum(int num) {
        int n = data.size();
        data.insert(num);
        
        if (n == 0) {
            mid = data.begin();
        } else if (num < *mid) {
            if (n % 2 == 0) {
                mid = prev(mid);
            }
        } else {
            if (n % 2 == 1) {
                mid = next(mid);
            }
        }
    }
    
    double findMedian() {
        int n = data.size();
        if (n % 2 == 0) {
            return (*mid + *next(mid, - 1)) * 0.5;
        } else {
            return *mid;
        }
    }
    
    multiset<int> data;
    multiset<int>::iterator mid;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
