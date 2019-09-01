class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.insert(number);    
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto num : nums) {
            int need = value - num;
            if (need == num) {
                if (nums.count(need) > 1) {
                    return true;
                }
            } else {
                if (nums.find(need) != nums.end()) {
                    return true;
                }
            }
        }
        return false;
    }
    
    multiset<int> nums;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
