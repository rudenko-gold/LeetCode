class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> emailsSet;
        for (string email : emails) {
            auto at_it = email.find('@');
            string local_name(email.begin(), email.begin() + at_it);
            string domain(email.begin() + at_it, email.end());
            
            string finally_local_name;
            finally_local_name.reserve(local_name.size());
            for (size_t i = 0; i < local_name.size(); ++i) {
                if (local_name[i] == '.') {
                    continue;
                } else if (local_name[i] == '+') {
                    break;
                } else {
                    finally_local_name.push_back(local_name[i]);
                }
            }
            finally_local_name.shrink_to_fit();
            emailsSet.insert(finally_local_name + domain);
        }
        
        return emailsSet.size();
    }
};
