class Solution {
public:  
    struct Time {
        int h;
        int m;
        
        bool operator< (Time t2) {
            if (this->h == t2.h) {
                return this->m < t2.m;
            } else {
                return this->h < t2.h;
            }
        }
    };
    
    bool isValid(Time t) {
        if (t.h >= 0 && t.h < 24 && t.m >= 0 && t.m < 60) {
            return true;
        } else {
            return false;
        }
    }
    
    string toString(Time t) {
        string ans = "";
        ans += char(t.h / 10 + '0');
        ans += char(t.h % 10 + '0');
        ans += ':';
        ans += char(t.m / 10 + '0');
        ans += char(t.m % 10 + '0');
        return ans;
    }
    
    string largestTimeFromDigits(vector<int>& a) {
        sort(a.begin(), a.end());
        Time ansTime;
        ansTime.h = -1;
        ansTime.m = -1;
        do {
            Time t;
            t.h = a[0] * 10 + a[1];
            t.m = a[2] * 10 + a[3];
            
            if (isValid(t) && ansTime < t) {
                ansTime = t;
            }
        } while (next_permutation(a.begin(), a.end()));
        
        if (ansTime.h == -1) {
            return "";
        } else {
            return toString(ansTime);
        }
    }
};
