class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : window_size(size) {
        
    }
    
    double next(int val) {
        range.push(val);
        sum += val;
        if (range.size() > window_size) {
            sum -= range.front();
            range.pop();
        }
        return sum / range.size();
    }
    
    queue<int> range;
    double sum = 0;
    int window_size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
