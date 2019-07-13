class Solution {
public:
    int binaryGap(int n) {
        string bin = "";
        while (n > 0) {
            bin += char('0' + (n % 2));
            n /= 2;
        }
        int ans = 0;
        int lastOne = -1;
        for (int i = 0; i < bin.size(); ++i) {
            if (bin[i] == '1') {
                if (lastOne != -1) {
                    ans = max(ans, i - lastOne);
                }
                lastOne = i;
            }
        }
        return ans;
    }
};
