class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            strNums[i] = to_string(nums[i]);
        }
        
        sort(strNums.begin(), strNums.end(), [](string n1, string n2) {
            return n1 + n2 > n2 + n1;
        });
        
        string ans = "";
        
        for (int i = 0; i < strNums.size(); ++i) {
            ans += strNums[i];
        }
        
        if (ans[0] == '0') {
            return "0";
        }
        
        return ans;
    }
};
