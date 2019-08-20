class Solution {
public:
    string toGoatLatin(string S) {
        string addition = "a";
        
        stringstream ss(S);
        string ans = "";
        
        const set<char> vowel = { 'a', 'e', 'i', 'o', 'u' };
        
        while (!ss.eof()) {
            string word;
            ss >> word;
            if (vowel.find(tolower(word[0])) == vowel.end()) {
                word.push_back(word[0]);
                word.erase(word.begin());
            }
            word += "ma";
            word += addition;
            addition += "a";
            ans += word + " ";
        }
        ans.pop_back();
        return ans;   
    }
};
