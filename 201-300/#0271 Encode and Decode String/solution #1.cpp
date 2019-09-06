class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_str = "";
        for (auto& str : strs) {
            encoded_str += str + char(255);
        }
        return encoded_str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        string curr = "";
        vector<string> decoded_vector;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == char(255)) {
                decoded_vector.push_back(curr);
                curr = "";
            } else {
                curr += s[i];
            }
        }
        
        return decoded_vector;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
