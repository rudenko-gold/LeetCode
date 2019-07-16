class RLEIterator {
public:
    RLEIterator(vector<int>& a) {
        data = a;
    }
    
    int next(int n) {
        int ret_value = -1;
        while (n > 0) {
            if (curr_pos >= data.size()) {
                return -1;
            }
            
            if (data[curr_pos] >= n) {
                ret_value = data[curr_pos + 1];
                data[curr_pos] -= n;
                n = 0;
            } else if (data[curr_pos] > 0) {
                ret_value = data[curr_pos + 1];
                n -= data[curr_pos];
                data[curr_pos] = 0;
            } else {
                curr_pos += 2;
            }
        }
        
        return ret_value;
    }
    
    vector<int> data;
    int curr_pos = 0;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
