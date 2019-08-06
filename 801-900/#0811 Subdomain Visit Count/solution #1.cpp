class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> hashMap;
        
        for (auto& input : cpdomains) {
            stringstream ss(input);
            int count;
            string domain;
            ss >> count >> domain;
            string sub_domain = "";
            reverse(domain.begin(), domain.end());
            for (auto c : domain) {
                if (c == '.') {
                    reverse(sub_domain.begin(), sub_domain.end());
                    hashMap[sub_domain] += count;
                    reverse(sub_domain.begin(), sub_domain.end());
                } 
                sub_domain += c;
            }
            reverse(sub_domain.begin(), sub_domain.end());
            hashMap[sub_domain] += count;
        }
        
        vector<string> ans;
        
        for (auto& [key, value] : hashMap) {
            ans.push_back(to_string(value) + " " + key);
        }
        
        return ans;
    }
};
