class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        
        for (int hh = 0; hh < 12; hh++) {
            for (int mm = 0; mm < 60; mm++) {
                if (calcOnes(hh) + calcOnes(mm) == num) {
                    ans.push_back(timeToString(hh, mm));
                }
            }
        }
        return ans;
    }
    
    int calcOnes(int num) {
        int ans = 0;
        while (num > 0) {
            ans += num % 2;
            num /= 2;
        }
        return ans;
    }
    
    string timeToString(int hh, int mm) {
        return to_string(hh) + ":" + to_string(mm / 10) + to_string(mm % 10);
    }
};
